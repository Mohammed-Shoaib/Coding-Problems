# Problem Statement: https://www.hackerrank.com/challenges/detect-the-email-addresses/problem

import re
import sys

_ = input()
emails = re.findall(r'\b[\w.]+@[\w.]+\b', sys.stdin.read())
emails = sorted(set(emails))
print(';'.join(emails))