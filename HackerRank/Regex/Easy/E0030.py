# Problem Statement: https://www.hackerrank.com/challenges/detecting-valid-latitude-and-longitude/problem

import re

for _ in range(int(input())):
	print('Valid' if re.match(r'\([+-]?([0-8]\d?(\.\d+)?|90(\.0+)?),\s[+-]?((\d{1,2}|1[0-7]\d)(\.\d+)?|180(\.0+)?)\)$', input()) else 'Invalid')