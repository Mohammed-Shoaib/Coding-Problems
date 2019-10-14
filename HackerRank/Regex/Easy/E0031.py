# Problem Statement: https://www.hackerrank.com/challenges/hackerrank-tweets/problem

import re

print(sum(bool(re.search(r'(?i)hackerrank', input())) for _ in range(int(input()))))