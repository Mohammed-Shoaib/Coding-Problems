# Problem Statement: https://www.hackerrank.com/challenges/py-collections-deque/problem

from collections import deque

d = deque()
for _ in range(int(input())):
	cmd, *args = input().split()
	getattr(d, cmd)(*args)
print(*d)