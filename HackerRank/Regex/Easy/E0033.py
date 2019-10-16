# Problem Statement: https://www.hackerrank.com/challenges/utopian-identification-number/problem

import re

for _ in range(int(input())):
	print('VALID' if re.match(r'[a-z]{,3}\d{2,8}[A-Z]{3,}$', input()) else 'INVALID')