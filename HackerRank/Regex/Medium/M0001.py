# Problem Statement: https://www.hackerrank.com/challenges/detect-html-links/problem

import re
import sys

_ = input()

for link, text in re.findall(r'<a\s+href="(.*?)".*?>([^>]*?)</', sys.stdin.read()):
	print(link, text.strip(), sep=',')