# Problem Statement: https://www.hackerrank.com/challenges/validating-credit-card-number/problem

import re

def is_valid(card):
	return re.search(r'^(?!.*(\d)(-?\1){3})[456]\d{3}(-?\d{4}){3}$', card)

for _ in range(int(input())):
	print('Valid' if is_valid(input()) else 'Invalid')