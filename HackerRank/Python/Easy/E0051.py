# Problem Statement: https://www.hackerrank.com/challenges/zipped/problem

N, X = map(int, input().split())
l = [map(float, input().split()) for _ in range(X)]

for scores in zip(*l):
	print(sum(scores)/X)