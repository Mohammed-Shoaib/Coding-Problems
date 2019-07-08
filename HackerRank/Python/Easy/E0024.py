# Problem Statement: https://www.hackerrank.com/challenges/itertools-product/problem

from itertools import product

A = map(int, input().split())
B = map(int, input().split())

print(*product(A, B))