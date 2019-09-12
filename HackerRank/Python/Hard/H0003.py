# Problem Statement: https://www.hackerrank.com/challenges/matrix-script/problem

import re
import sys

s = ''
_, lines = input(), sys.stdin.read().split('\n')

for line in zip(*lines):
	s += ''.join(line)

print(re.sub(r'(?<=[A-Za-z0-9])[^A-Za-z0-9]+(?=[A-Za-z0-9])', ' ', s))