# Problem Statement: https://www.hackerrank.com/challenges/uk-and-us/problem

import re

sentence = '\n'.join([input() for _ in range(int(input()))])

for _ in range(int(input())):
	words = re.findall(r'\b' + input()[:-2] + r'[sz]e\b', sentence)
	print(len(words))