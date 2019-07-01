# Problem Statement: https://www.hackerrank.com/challenges/piling-up/problem

from collections import deque

for _ in range(int(input())):
	n, cubes = int(input()), deque(map(int, input().split()))

	for i in range(n - 1):
		if cubes[0] >= cubes[1]:
			cubes.popleft()
		elif cubes[-1] >= cubes[-2]:
			cubes.pop()
		else:
			break

	print("Yes" if len(cubes) == 1 else "No")