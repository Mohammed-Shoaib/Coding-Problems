# Problem Statement: https://www.hackerrank.com/challenges/detect-the-domain-name/problem

import re
import sys

_ = input()
domains = re.findall(r'(?i)https?://(?:www\.)?([\w.-]+\.[a-z\d]+)', sys.stdin.read())
domains = sorted(set(domains))
print(';'.join(domains))