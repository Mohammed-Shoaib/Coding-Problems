# Problem Statement: https://www.hackerrank.com/challenges/validating-the-phone-number/problem

import re

matches = ['YES' if re.match(r'[789]\d{9}$', input()) else 'NO' for _ in range(int(input()))]
print(*matches, sep='\n')