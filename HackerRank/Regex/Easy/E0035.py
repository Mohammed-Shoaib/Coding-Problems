# Problem Statement: https://www.hackerrank.com/challenges/find-hackerrank/problem

import re

for _ in range(int(input())):
	conv = input()
	start = bool(re.match(r'hackerrank', conv))
	end = bool(re.match(r'.*hackerrank$', conv))
	cond = [start and end, start, end]
	print(cond.index(True) if True in cond else -1)