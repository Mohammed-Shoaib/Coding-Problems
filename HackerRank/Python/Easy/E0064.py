# Problem Statement: https://www.hackerrank.com/challenges/re-findall-re-finditer/problem

import re

matches = re.findall(r'[^aeiou]([aeiou]{2,})(?=[^aeiou])', input(), re.IGNORECASE)
print(*matches if matches else [-1], sep='\n')