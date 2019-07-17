# Problem Statement: https://www.hackerrank.com/challenges/itertools-combinations-with-replacement/problem

from itertools import combinations_with_replacement

S, k = input().split()

for comb in combinations_with_replacement(sorted(S), int(k)):
	print(''.join(comb))