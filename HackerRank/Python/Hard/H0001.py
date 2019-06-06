# Problem Statement: https://www.hackerrank.com/challenges/maximize-it/problem

from itertools import product

def f(X):
	return X * X

K, M = map(int, input().split())
N = [list(map(int, input().split()))[1:] for _ in range(K)]
S = [sum(map(f, prod)) % M for prod in product(*N)]
print(max(S))