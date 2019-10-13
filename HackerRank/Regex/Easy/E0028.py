# Problem Statement: https://www.hackerrank.com/challenges/alien-username/problem

import re

for _ in range(int(input())):
	print('VALID' if re.match(r'(?i)(_|\.)\d+[a-z]*_?$', input()) else 'INVALID')