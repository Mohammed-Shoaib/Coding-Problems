# Problem Statement: https://www.hackerrank.com/challenges/valid-pan-format/problem

import re

for _ in range(int(input())):
	print('YES' if re.match(r'[A-Z]{5}\d{4}[A-Z]$', input()) else 'NO')