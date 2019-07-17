# Problem Statement: https://www.hackerrank.com/challenges/itertools-combinations/problem

from itertools import combinations

S, k = input().split()
S, k = sorted(S), int(k)

for i in range(1, k + 1):
	for comb in combinations(S, i):
		print(''.join(comb))