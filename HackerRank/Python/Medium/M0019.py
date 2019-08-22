# Problem Statement: https://www.hackerrank.com/challenges/re-sub-regex-substitution/problem

import re

for _ in range(int(input())):
	line = re.sub(r'(?<=\s)&&(?=\s)', 'and', input())
	line = re.sub(r'(?<=\s)\|\|(?=\s)', 'or', line)
	print(line)