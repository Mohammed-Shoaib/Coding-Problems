# Problem Statement: https://www.hackerrank.com/challenges/iterables-and-iterators/problem

from itertools import combinations

_, N = int(input()), input().split()
K = int(input())
count = [1 if 'a' in comb else 0 for comb in combinations(N, K)]
print('%.3f' % (sum(count)/len(count)))