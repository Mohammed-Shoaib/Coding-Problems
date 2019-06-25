# Problem Statement: https://www.hackerrank.com/challenges/merge-the-tools/problem

from collections import OrderedDict

def merge_the_tools(s, k):
	for i in range(0, len(s), k):
		print(''.join(OrderedDict.fromkeys(s[i : i+k])))