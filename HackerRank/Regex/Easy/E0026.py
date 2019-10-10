# Problem Statement: https://www.hackerrank.com/challenges/detect-html-tags/problem

import re
import sys

_, html = input(), sys.stdin.read()
tags = sorted(set(re.findall(r'<\s*(\w+)', html)))
print(';'.join(tags))