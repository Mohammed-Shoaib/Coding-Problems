# Problem Statement: https://www.hackerrank.com/challenges/python-sort-sort/problem

N, M = map(int, input().split())
rows = [list(map(int, input().split())) for _ in range(N)]
K = int(input())
rows = sorted(rows, key=lambda x: x[K])
for row in rows:
	print(*row, sep=' ')