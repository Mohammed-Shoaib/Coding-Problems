# Problem Statement: https://www.hackerrank.com/challenges/re-start-re-end/problem

import re

S, k = input(), input()
matches = [(match.start(1), match.end(1) - 1) for match in re.finditer(f'(?=({k}))', S)]
print(*matches if matches else [(-1, -1)], sep='\n')