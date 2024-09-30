# Codeforces API Docs: https://codeforces.com/apiHelp

import sys

from itertools import groupby
from pathlib import Path
from time import sleep
from typing import Any, Callable, Dict, List

from bs4 import BeautifulSoup
from selenium import webdriver
from selenium.common.exceptions import NoSuchElementException
from selenium.webdriver import FirefoxOptions
from webdriver_manager.firefox import GeckoDriverManager

import requests


HANDLE = ""
PASSWORD = ""  # used for gym submissions via selenium
OUTPUT_PATH = Path("./Codeforces/")
LOG = True

CODEFORCES_API = "https://codeforces.com/api/"
CODEFORCES_URL = "https://codeforces.com/"

REQUESTS_TIMEOUT = 10
USER_STATUS = "user.status?handle={handle}&from={fromIndex}&count={count}"


class CodeforcesSubmission:
    web_client = None

    def __init__(self, id_: int, contest_id: int, problem_id: str, problem_name: str, language: str, verdict: str):
        self.id_: int = id_
        self.contest_id: str = f"{contest_id:04}"
        self.problem_id: str = problem_id
        self.problem_name: str = problem_name
        self.language: str = language
        self.verdict: str = verdict
        self._code: str = ""

        if len(str(contest_id)) == 6:
            self.link = f"https://codeforces.com/gym/{contest_id}/submission/{self.id_}"
            self.problem_link = f"https://codeforces.com/gym/{contest_id}/problem/{self.problem_id}"

        else:
            self.link = f"https://codeforces.com/contest/{contest_id}/submission/{self.id_}"
            self.problem_link = f"https://codeforces.com/contest/{contest_id}/problem/{self.problem_id}"

    @property
    def code(self) -> str:
        if len(self._code) == 0:
            if LOG:
                print(f"Requesting content of submission {self.id_}... ", end="")

            if len(self.contest_id) == 6:
                if CodeforcesSubmission.web_client is None:
                    options = FirefoxOptions()
                    options.headless = True
                    CodeforcesSubmission.web_client = webdriver.Firefox(
                        executable_path=GeckoDriverManager().install(),
                        options=options
                    )
                    CodeforcesSubmission.web_client.get(CODEFORCES_URL)
                    login_link = CodeforcesSubmission.web_client.find_element_by_link_text("Enter")
                    login_link.click()
                    sleep(10)
                    handle_input = CodeforcesSubmission.web_client.find_element_by_id("handleOrEmail")
                    handle_input.send_keys(HANDLE)
                    password_input = CodeforcesSubmission.web_client.find_element_by_id("password")
                    password_input.send_keys(PASSWORD)
                    login_btn = CodeforcesSubmission.web_client.find_element_by_class_name("submit")
                    login_btn.click()
                    sleep(10)
                    try:
                        CodeforcesSubmission.web_client.find_element_by_class_name("shiftUp")
                        print("Critical: credentials error!")
                        sys.exit(1)

                    except NoSuchElementException:
                        pass

                CodeforcesSubmission.web_client.get(self.link)
                sleep(3)
                self._code = CodeforcesSubmission.extract_code(CodeforcesSubmission.web_client.page_source)
                if LOG:
                    print("ok!")

            else:
                response = requests.get(self.link, timeout=REQUESTS_TIMEOUT)
                sleep(1)
                if response.status_code == 200:
                    self._code = CodeforcesSubmission.extract_code(response.content.decode("utf-8"))
                    if LOG:
                        print("ok!")

                else:
                    if LOG:
                        print("error!")
                    print(f"An error happened. Couldn't retrieve url content for submission id {self.id_}.")
                    print(f"Status code: {response.status_code}")

        return self._code

    @staticmethod
    def quit() -> None:
        if CodeforcesSubmission.web_client is not None:
            CodeforcesSubmission.web_client.quit()

    @staticmethod
    def extract_code(html: str) -> str:
        code_obj = BeautifulSoup(html, "html.parser").find("pre", id="program-source-text").next
        return "\n".join(code_obj.get_text(strip=True).splitlines()) \
            if code_obj.name != "ol" \
            else "\n".join(li.get_text().rstrip() for li in code_obj)


def get_user_submissions(
    handle: str, count_: int, *, filter_: Callable[[Dict[str, Any]], bool], max_: int
) -> List[CodeforcesSubmission]:
    submissions: List[CodeforcesSubmission] = []
    index = 1
    finished = False
    while not finished and len(submissions) != max_:
        response: requests.Response = requests.get(
            f"{CODEFORCES_API}{USER_STATUS.format(handle=handle, fromIndex=index, count=count_)}",
            timeout=REQUESTS_TIMEOUT
        )
        sleep(1)
        if response.status_code == 200:
            json: Dict[str, Any] = response.json()
            finished = len(json["result"]) == 0

            for submission in filter(filter_, json["result"]):
                submissions.append(CodeforcesSubmission(
                    submission["id"], submission["contestId"], submission["problem"]["index"],
                    submission["problem"]["name"], submission["programmingLanguage"], submission["verdict"]
                ))
                if len(submissions) == max_:
                    break

            index += count_

        else:
            print(f"An error happened. Status code for getting user submissions: {response.status_code}")
            finished = True

    if LOG:
        print(f"Successfully retrieved {len(submissions)} submissions from {handle}")

    return submissions


def save_submissions(
    output_path: Path, handle: str, count: int = 1000, *,
    filter_: Callable[[Dict[str, Any]], bool] = lambda s: True, max_: int = -1
):
    def _normalize(submissions: List[CodeforcesSubmission]) -> groupby:
        def _key(submission: CodeforcesSubmission) -> str:
            return f"{submission.contest_id}{submission.problem_id}"
        return groupby(sorted(submissions, key=_key), _key)

    def _language_extension(language: str) -> str:
        ext = {
            "GNU C11": "c",
            "GNU C++": "cpp",
            "GNU C++11": "cpp",
            "GNU C++14": "cpp",
            "MS C#": "cs",
            "Python 3": "py",
        }
        if language not in ext:
            raise Exception(f"Not recognized language {language} for extension. Please add it!")

        return ext[language]

    def _language_comment(language: str, comment: str) -> str:
        com = {
            "GNU C11": "// {0}",
            "GNU C++": "// {0}",
            "GNU C++11": "// {0}",
            "GNU C++14": "// {0}",
            "MS C#": "// {0}",
            "Python 3": "# {0}",
        }
        if language not in com:
            raise Exception(f"Not recognized language {language} for comments. Please add it!")

        return com[language].format(comment)

    def _save_submission(path: Path, submission: CodeforcesSubmission) -> None:
        with open(path, "w", encoding="utf8") as sub_file:
            sub_file.write(_language_comment(submission.language, f"Problem name: {submission.problem_name}") + "\n")
            sub_file.write(_language_comment(submission.language, f"Problem link: {submission.problem_link}") + "\n")
            sub_file.write(_language_comment(submission.language, f"Submission link: {submission.link}") + "\n\n")
            sub_file.write(submission.code)

    def _save_submissions(path: Path, submissions: List[CodeforcesSubmission]) -> None:
        path.mkdir(parents=True, exist_ok=True)
        name = f"{submissions[0].contest_id}{submissions[0].problem_id}"
        if len(submissions) == 1:
            _save_submission(
                path / f"{submissions[0].problem_id}.{_language_extension(submissions[0].language)}",
                submissions[0]
            )
            if LOG:
                print(f"Submission for {name} successfully saved")

        else:
            for i, submission in enumerate(submissions, start=1):
                _save_submission(
                    path / f"{submissions[0].problem_id}-{i}.{_language_extension(submissions[i - 1].language)}",
                    submission
                )
                if LOG:
                    print(f"Submission for {name}-{i} successfully saved")

    submissions: List[CodeforcesSubmission] = get_user_submissions(handle, count, filter_=filter_, max_=max_)
    output_path.mkdir(parents=True, exist_ok=True)
    folder = {
        4: "Contests",
        6: "Gym"
    }
    for _, sub_ in _normalize(submissions):
        submissions = list(sub_)
        _save_submissions(
            output_path / folder[len(submissions[0].contest_id)] / submissions[0].contest_id,
            submissions
        )


if __name__ == "__main__":
    def _accepted_filter(submission: Dict[str, Any]) -> bool:
        return submission["verdict"] == "OK"

    COUNT = 1000
    ALL = -1
    save_submissions(OUTPUT_PATH, HANDLE, COUNT, filter_=_accepted_filter, max_=ALL)
    CodeforcesSubmission.quit()
