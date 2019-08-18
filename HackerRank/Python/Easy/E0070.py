# Problem Statement: https://www.hackerrank.com/challenges/validating-uid/problem

import re

def is_valid(string):
	return re.search(r'^(?!.*(.).*\1)(?=(.*?[A-Z]){2})(?=(.*?\d){3})[a-zA-Z0-9]{10}$', string)

for _ in range(int(input())):
	print('Valid' if is_valid(input()) else 'Invalid')