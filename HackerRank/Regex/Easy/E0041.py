# Problem Statement: https://www.hackerrank.com/challenges/uk-and-us-2/problem

import re

sentence = '\n'.join([input() for _ in range(int(input()))])

for _ in range(int(input())):
	words = re.findall(r'\b' + input().replace('our', 'ou?r') + r'\b', sentence)
	print(len(words))