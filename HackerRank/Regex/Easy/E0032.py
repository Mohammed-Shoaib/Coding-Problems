# Problem Statement: https://www.hackerrank.com/challenges/stack-exchange-scraper/problem

import re
import sys

questions = re.findall(r'summary-(\d+).*?hyperlink">([^<]+).*?"relativetime">([^<]+)', sys.stdin.read(), flags=re.DOTALL)
for question in questions:
	print(*question, sep=';')