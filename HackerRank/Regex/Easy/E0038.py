# Problem Statement: https://www.hackerrank.com/challenges/split-number/problem

import re

for _ in range(int(input())):
	codes = re.findall(r'^(\d{1,3})[-\s](\d{1,3})[-\s](\d{4,10})$', input())[0]
	print('CountryCode={},LocalAreaCode={},Number={}'.format(*codes))