# Problem Statement: https://www.hackerrank.com/challenges/hex-color-code/problem

import re
import sys

_, css = input(), sys.stdin.read()
valid = re.findall(r'#[\da-f]+\b(?!\s*\{)', css, flags=re.IGNORECASE)
print(*filter(lambda x: len(x) != 3 or len(x) != 6, valid), sep='\n')