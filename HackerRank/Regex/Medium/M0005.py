# Problem Statement: https://www.hackerrank.com/challenges/ide-identifying-comments/problem

import re
import sys

comments = re.findall(r'/(?:/[^\n]*|\*.*?\*/)', sys.stdin.read(), re.DOTALL)
for comment in comments:
	print(re.sub(r'\n\s+', r'\n', comment))