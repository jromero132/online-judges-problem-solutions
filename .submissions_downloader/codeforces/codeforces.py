# Codeforces API Docs: https://codeforces.com/apiHelp

from bs4 import BeautifulSoup
from itertools import groupby
from pathlib import Path
from selenium import webdriver
from selenium.webdriver import FirefoxOptions
from time import sleep

import requests


HANDLE = ""
PASSWORD = "" # used for gym submissions via selenium
OUTPUT_PATH = Path("./Codeforces/")
LOG = True

CODEFORCES_API = "https://codeforces.com/api/"
CODEFORCES_URL = "https://codeforces.com/"


class CodeforcesSubmission:
	web_client = None

	def __init__(self, id, contest_id, problem_id, problem_name, language, verdict):
		self.id = id
		self.contest_id = f"{contest_id:04}"
		self.problem_id = problem_id
		self.problem_name = problem_name
		self.language = language
		self.verdict = verdict
		if len(str(contest_id)) == 6:
			self.link = f"https://codeforces.com/gym/{contest_id}/submission/{self.id}"
			self.problem_link = f"https://codeforces.com/gym/{contest_id}/problem/{self.problem_id}"
		else:
			self.link = f"https://codeforces.com/contest/{contest_id}/submission/{self.id}"
			self.problem_link = f"https://codeforces.com/contest/{contest_id}/problem/{self.problem_id}"
		self._code = None
		self._web_client = None

	@property
	def code(self):
		if self._code is None:
			if LOG:
				print(f"Requesting content of submission {self.id}... ", end = "")

			if len(self.contest_id) == 6:
				if CodeforcesSubmission.web_client is None:
					options = FirefoxOptions()
					options.headless = True
					CodeforcesSubmission.web_client = webdriver.Firefox(options = options)
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
						invalid = CodeforcesSubmission.web_client.find_element_by_class_name("shiftUp")
						print("Critical: credentials error!")
						exit(1)
					except:
						pass

				CodeforcesSubmission.web_client.get(self.link)
				sleep(3)
				self._code = CodeforcesSubmission.extract_code(CodeforcesSubmission.web_client.page_source)
				if LOG:
					print("ok!")


			else:
				response = requests.get(self.link)
				sleep(1)
				if response.status_code == 200:
					self._code = CodeforcesSubmission.extract_code(response.content)
					if LOG:
						print("ok!")

				else:
					if LOG:
						print("error!")
					print(f"An error happened. Couldn't retrieve url content for submission id {self.id}. Status code: {response.status_code}")
		return self._code

	@staticmethod
	def extract_code(html):
		code_obj = BeautifulSoup(html, "html.parser").find("pre", id = "program-source-text").next
		return "\n".join(code_obj.get_text(strip = True).splitlines()) if code_obj.name != "ol" else "\n".join(li.get_text().rstrip() for li in code_obj)


def get_user_submissions(handle, count, *, filter_ , max_):
	USER_STATUS = "user.status?handle={handle}&from={fromIndex}&count={count}"
	submissions = []
	index = 1
	finished = False
	while not finished and len(submissions) != max_:
		response = requests.get(f"{CODEFORCES_API}{USER_STATUS.format(handle = handle, fromIndex = index, count = count)}")
		sleep(1)
		if response.status_code == 200:
			json = response.json()
			finished = len(json[ "result" ]) == 0
			for s in filter(filter_, json[ "result" ]):
				submissions.append(CodeforcesSubmission(s[ "id" ], s[ "contestId" ], s[ "problem" ][ "index" ], s[ "problem" ][ "name" ], s[ "programmingLanguage" ], s[ "verdict" ]))
				if len(submissions) == max_:
					break
			index += count

		else:
			print(f"An error happened. Status code for getting user submissions: {response.status_code}")
			finished = True

	if LOG:
		print(f"Successfully retrieved {len(submissions)} submissions from {handle}")
	return submissions


def save_submissions(output_path, handle, count = 1000, *, filter_ = lambda s: True, max_ = -1):
	def normalize(submissions):
		key = lambda s: f"{s.contest_id}{s.problem_id}"
		return groupby(sorted(submissions, key = key), key)

	def language_extension(language):
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
		return ext[ language ]

	def language_comment(language, comment):
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
		return com[ language ].format(comment)

	def _save_submission(path, submission):
		with open(path, "w", encoding = "utf8") as f:
			f.write(language_comment(submission.language, f"Problem name: {submission.problem_name}") + "\n")
			f.write(language_comment(submission.language, f"Problem link: {submission.problem_link}") + "\n")
			f.write(language_comment(submission.language, f"Submission link: {submission.link}") + "\n\n")
			f.write(submission.code)

	def _save_submissions(path, submissions):
		path.mkdir(parents = True, exist_ok = True)
		name = f"{submissions[ 0 ].contest_id}{submissions[ 0 ].problem_id}"
		if len(submissions) == 1:
			_save_submission(path / f"{submissions[ 0 ].problem_id}.{language_extension(submissions[ 0 ].language)}", submissions[ 0 ])
			if LOG:
				print(f"Submission for {name} successfully saved")
		else:
			for i, s in enumerate(submissions, start = 1):
				_save_submission(path / f"{submissions[ 0 ].problem_id}-{i}.{language_extension(submissions[ i - 1 ].language)}", s)
				if LOG:
					print(f"Submission for {name}-{i} successfully saved")

	submissions = get_user_submissions(handle, count, filter_ = filter_, max_ = max_)
	output_path.mkdir(parents = True, exist_ok = True)
	folder = {
		4: "Contests",
		6: "Gym"
	}
	for dname, sub_ in normalize(submissions):
		s = list(sub_)
		_save_submissions(output_path / folder[ len(s[ 0 ].contest_id) ] / s[ 0 ].contest_id, s)

if __name__ == "__main__":
	count = 1000
	accepted_filter = lambda s: s[ "verdict" ] == "OK"
	all = -1
	save_submissions(OUTPUT_PATH, HANDLE, count, filter_ = accepted_filter, max_ = all)