# Problem Statement: https://www.hackerrank.com/challenges/defaultdict-tutorial/problem

from collections import defaultdict

n, m = map(int, input().split())
d = defaultdict(list)

for i in range(n):
    d[input()].append(i + 1)

for _ in range(m):
    print(' '.join(map(str, d[input()])) or -1)