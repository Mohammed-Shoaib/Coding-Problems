# Problem Statement: https://www.hackerrank.com/challenges/saying-hi/problem

import re
import sys

_ = input()
print('\n'.join(re.findall(r'^(?i)(hi\s[^d].*)$', sys.stdin.read(), flags=re.MULTILINE)))