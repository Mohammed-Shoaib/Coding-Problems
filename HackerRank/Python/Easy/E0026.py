# Problem Statement: https://www.hackerrank.com/challenges/itertools-permutations/problem

from itertools import permutations

S, k = input().split()

for perm in permutations(sorted(S), int(k)):
    print(''.join(perm))