import sys

from itertools import groupby
from pathlib import Path
from time import sleep
from typing import Callable, List, Tuple

from bs4 import BeautifulSoup
from selenium import webdriver
from selenium.common.exceptions import NoSuchElementException
from selenium.webdriver import FirefoxOptions
from webdriver_manager.firefox import GeckoDriverManager


USERNAME = ""
PASSWORD = ""
OUTPUT_PATH = Path("./MOG/")
LOG = True

MOG_URL = "https://matcomgrader.com"


class MOGSubmission:
    def __init__(self, id_: str, link: str, problem_name: str, problem_link: str, language: str, verdict: str):
        self.id_: str = id_
        self.link: str = link
        self.problem_name: str = problem_name
        self.problem_link: str = problem_link
        self.language: str = language
        self.verdict: str = verdict


def login(web_client: webdriver.Remote, username: str, password: str) -> None:
    web_client.get(MOG_URL)
    login_link = web_client.find_element_by_link_text("Login")
    login_link.click()
    sleep(5)
    username_input = web_client.find_element_by_name("username")
    username_input.send_keys(username)
    password_input = web_client.find_element_by_name("password")
    password_input.send_keys(password)
    login_btn = web_client.find_element_by_xpath('//input[@type="submit" and @value="Login"]')
    login_btn.click()
    sleep(5)
    try:
        login_btn = web_client.find_element_by_xpath('//input[@type="submit" and @value="Login"]')
        print("Critical: credentials error!")
        sys.exit(1)

    except NoSuchElementException:
        pass


def save_submissions(
    output_path: Path, credentials: Tuple[str, str],
    *, filter_: Callable[[MOGSubmission], bool] = lambda s: True, max_: int = -1
):
    username, password = credentials
    options = FirefoxOptions()
    options.headless = True
    web_client = webdriver.Firefox(executable_path=GeckoDriverManager().install(), options=options)
    login(web_client, username, password)
    page = 1
    link = f"{MOG_URL}/submissions/?username={username}&page="
    submissions: List[MOGSubmission] = []
    while len(submissions) != max_:
        web_client.get(link + str(page))
        cur_page: str = web_client.find_element_by_class_name("active").text
        if int(cur_page) < page:
            break

        page_submissions = web_client.find_elements_by_class_name("info")
        for page_submission in page_submissions:
            html = page_submission.get_attribute("innerHTML")
            soup = BeautifulSoup(html, "html.parser")
            properties = soup.find_all(recursive=False)
            submission = MOGSubmission(
                id_=properties[0].get_text(strip=True),
                link=f"{MOG_URL}{properties[0].find_next('a')['href']}",
                problem_name=properties[3].get_text(strip=True),
                problem_link=f"{MOG_URL}{properties[3].find_next('a')['href']}",
                language=properties[7].get_text(strip=True),
                verdict=properties[4].get_text(strip=True)
            )
            if filter_(submission):
                submissions.append(submission)
                if len(submissions) == max_:
                    break

        page += 1

    if LOG:
        print(f"Successfully retrieved {len(submissions)} submissions from {username}")

    ext = {
        "GNU GCC 5.1.0": "c",
        "GNU G++ 5.1.0": "cpp",
        "GNU G++11 5.1.0": "cpp",
        "MS C# .NET 4.7": "cs"
    }
    com = {
        "GNU GCC 5.1.0": "// {0}",
        "GNU G++ 5.1.0": "// {0}",
        "GNU G++11 5.1.0": "// {0}",
        "MS C# .NET 4.7": "// {0}"
    }

    output_path.mkdir(parents=True, exist_ok=True)
    submissions.sort(key=lambda s: s.problem_name)
    for _, _isubmissions in groupby(submissions, key=lambda s: s.problem_name):
        _submissions: List[MOGSubmission] = list(_isubmissions)
        problem_slug: str = _submissions[0].problem_link.split('/')[-2]
        folder: Path = output_path / problem_slug
        folder.mkdir(parents=True, exist_ok=True)

        for i, submission in enumerate(_submissions):
            web_client.get(submission.link)
            sleep(3)
            soup = BeautifulSoup(web_client.page_source, "html.parser")
            code = soup.find("textarea", {"id": "source"})
            filename: str = f"{problem_slug}{'-' + str(i + 1) if len(_submissions) > 1 else ''}"
            with open(folder / f"{filename}.{ext[submission.language]}", "w", encoding="utf8") as sub_file:
                sub_file.write(com[submission.language].format(f"Problem name: {submission.problem_name}") + "\n")
                sub_file.write(com[submission.language].format(f"Problem link: {submission.problem_link}") + "\n")
                sub_file.write(com[submission.language].format(f"Submission link: {submission.link}") + "\n\n")
                sub_file.write(code.get_text(strip=True))

            if LOG:
                print(f"Submission for {filename} successfully saved")

    web_client.quit()


if __name__ == "__main__":
    def _accepted_filter(submission: MOGSubmission) -> bool:
        return submission.verdict == "Accepted"

    ALL = -1
    save_submissions(OUTPUT_PATH, (USERNAME, PASSWORD), filter_=_accepted_filter, max_=ALL)
