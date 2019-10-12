# Problem Statement: https://www.hackerrank.com/challenges/find-substring/problem

import re

sentences = '\n'.join([input() for _ in range(int(input()))])

for _ in range(int(input())):
	sub_words = re.findall(r'\w(?=%s\w)' % input(), sentences)
	print(len(sub_words))