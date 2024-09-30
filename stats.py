from abc import ABC, abstractmethod
from collections import defaultdict
from pathlib import Path
from typing import Dict, List, Union

import plotly.graph_objects as go
from plotly.subplots import make_subplots


extensions: Dict[str, int] = defaultdict(int)


class Stats(ABC):
    def __init__(self, name: str, path: Union[None, Path] = None) -> None:
        super().__init__()
        self.name = name
        self.path = Path().absolute() / name if path is None else path
        self.clear()
        self.get_stats()

    def __repr__(self) -> str:
        return f"{self.name}<{self.problems}, {self.solutions}>"

    def __str__(self) -> str:
        return self.__repr__()

    def clear(self) -> None:
        self.summary: Dict[str, List[Path]] = defaultdict(list)
        self.problems = 0
        self.solutions = 0

    @abstractmethod
    def get_stats(self) -> None:
        pass


class SimpleStats(Stats):
    def get_stats(self):
        self.clear()
        for problem in self.path.iterdir():
            self.problems += 1
            for solution in problem.iterdir():
                self.solutions += 1
                self.summary[problem.name].append(solution)
                extensions[solution.suffix] += 1


class ComplexStats(Stats):
    def get_stats(self) -> None:
        self.clear()
        for contest in self.path.iterdir():
            for solution in sorted(contest.iterdir()):
                self.solutions += 1
                val = f"{contest.name}{solution.stem.split('-')[0]}"
                self.summary[val].append(solution)
                self.problems += len(self.summary[val]) == 1
                extensions[solution.suffix] += 1


class VeryComplexStats(Stats):
    def clear(self) -> None:
        self.summary: Dict[str, Dict[str, List[Path]]] = defaultdict(lambda: defaultdict(list))
        self.problems_per_contest: Dict[str, int] = defaultdict(int)
        self.solutions_per_contest: Dict[str, int] = defaultdict(int)
        self.problems = 0
        self.solutions = 0

    def get_stats(self) -> None:
        self.clear()
        for contest_type in self.path.iterdir():
            _summary: Dict[str, List[Path]] = defaultdict(list)
            _problems_per_contest = 0
            _solutions_per_contest = 0
            for contest in contest_type.iterdir():
                for solution in sorted(contest.iterdir()):
                    self.solutions += 1
                    _solutions_per_contest += 1
                    val = f"{contest.name}{solution.stem.split('-')[0]}"
                    _summary[val].append(solution)
                    self.problems += len(_summary[val]) == 1
                    _problems_per_contest += len(_summary[val]) == 1
                    extensions[solution.suffix] += 1

            self.summary[contest_type.name] = _summary
            self.problems_per_contest[contest_type.name] = _problems_per_contest
            self.solutions_per_contest[contest_type.name] = _solutions_per_contest


class CompoundStats(Stats):
    def __init__(self, name: str, stats: List[Stats], path: Union[None, Path] = None) -> None:
        self.stats = stats
        super().__init__(name, path)

    def get_stats(self) -> None:
        self.clear()
        for stat in self.stats:
            self.problems += stat.problems
            self.solutions += stat.solutions


class PlotData:
    def __init__(self):
        self.ids = []
        self.labels = []
        self.parents = []
        self.values = []

    def __repr__(self):
        return f"{self.__class__.__name__}(ids={self.ids},"\
                " labels={self.labels}, parents={self.parents}, values={self.values})"

    @staticmethod
    def get(stats, parent=""):
        cur_id = stats.name.lower()
        cur_parent = "" if parent == "" else parent + "_"

        problems_data = PlotData()
        problems_data.ids.append(f"{cur_parent}{cur_id}")
        problems_data.labels.append(f"{stats.name}<br>({stats.problems})")
        problems_data.parents.append(parent)

        solutions_data = PlotData()
        solutions_data.labels.append(f"{stats.name}<br>({stats.solutions})")

        if isinstance(stats, CompoundStats):
            idx = len(problems_data.values)
            problems_data.values.append(0)
            solutions_data.values.append(0)
            parent_id = f"{cur_parent}{cur_id}"
            for stat in stats.stats:
                pplot_data, splot_data = PlotData.get(stat, parent_id)
                problems_data.ids.extend(pplot_data.ids)
                problems_data.parents.extend(pplot_data.parents)

                problems_data.labels.extend(pplot_data.labels)
                problems_data.values.extend(pplot_data.values)
                problems_data.values[idx] += stat.problems

                solutions_data.labels.extend(splot_data.labels)
                solutions_data.values.extend(splot_data.values)
                solutions_data.values[idx] += stat.solutions

        else:
            problems_data.values.append(stats.problems)
            solutions_data.values.append(stats.solutions)

        solutions_data.ids = problems_data.ids.copy()
        solutions_data.parents = problems_data.parents.copy()
        return problems_data, solutions_data


all_stats = CompoundStats(
    "Total",
    [
        VeryComplexStats("Codeforces"),
        SimpleStats("CSAcademy"),
        SimpleStats("Kattis"),
        SimpleStats("MOG"),
        SimpleStats("SPOJ"),
        CompoundStats(
            "VJudge",
            [
                SimpleStats("Aizu", Path("VJudge") / "Aizu"),
                ComplexStats("AtCoder", Path("VJudge") / "AtCoder"),
                SimpleStats("CodeChef", Path("VJudge") / "CodeChef"),
                VeryComplexStats("Codeforces", Path("VJudge") / "Codeforces"),
                SimpleStats("HackerRank", Path("VJudge") / "HackerRank"),
                SimpleStats("LightOJ", Path("VJudge") / "LightOJ"),
                SimpleStats("POJ", Path("VJudge") / "POJ"),
                SimpleStats("SPOJ", Path("VJudge") / "SPOJ"),
                SimpleStats("TopCoder", Path("VJudge") / "TopCoder"),
                SimpleStats("URAL", Path("VJudge") / "URAL"),
                SimpleStats("UVA", Path("VJudge") / "UVA")
            ]
        )
    ],
    Path().absolute()
)

problems_plot_data, solutions_plot_data = PlotData.get(all_stats)
problems_plot_data.labels[0] = f"Problems Solved<br>({all_stats.problems})"
solutions_plot_data.labels[0] = f"Solutions<br>({all_stats.solutions})"

fig1 = make_subplots(
    rows=1, cols=2,
    specs=[[dict(type="sunburst"), dict(type="sunburst")]],
    horizontal_spacing=0,
)
fig1.add_trace(
    go.Sunburst(
        ids=problems_plot_data.ids,
        labels=problems_plot_data.labels,
        parents=problems_plot_data.parents,
        values=problems_plot_data.values,
        branchvalues="total",
    ),
    row=1,
    col=1
)
fig1.add_trace(
    go.Sunburst(
        ids=solutions_plot_data.ids,
        labels=solutions_plot_data.labels,
        parents=solutions_plot_data.parents,
        values=solutions_plot_data.values,
        branchvalues="total",
        marker=dict(colors=["#f5f5f5"])
    ),
    row=1,
    col=2
)
fig1.update_layout(
    uniformtext=dict(minsize=16, mode='hide'),
    margin=dict(t=0, l=0, r=0, b=0),
    paper_bgcolor='rgba(0,0,0,0)',
    plot_bgcolor='rgba(0,0,0,0)'
)
fig1.write_image(".resources/solutions.png", width=1280, height=720)

LANGUAGES = {
    ".c": "C",
    ".cpp": "C++",
    ".cs": "C#",
    ".py": "Python"
}
fig2 = go.Figure(
    go.Sunburst(
        ids=["total"] + list(LANGUAGES.keys()),
        labels=[f"Solutions<br>({all_stats.solutions})"] + [
            f"{LANGUAGES.get(key, key)}<br>({value})" for key, value in extensions.items()
        ],
        parents=[""] + ["total" for _ in range(len(extensions))],
        values=[all_stats.solutions] + list(extensions.values()),
        branchvalues="total",
        marker=dict(colors=["#f5f5f5"])
    )
)
fig2.update_layout(
    uniformtext=dict(minsize=13, mode='hide'),
    margin=dict(t=0, l=0, r=0, b=0),
    paper_bgcolor='rgba(0,0,0,0)',
    plot_bgcolor='rgba(0,0,0,0)'
)
fig2.write_image(".resources/languages.png", width=325, height=325)
