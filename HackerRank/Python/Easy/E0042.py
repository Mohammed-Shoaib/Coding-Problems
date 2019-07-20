# Problem Statement: https://www.hackerrank.com/challenges/py-set-union/problem

_, E = int(input()), set(map(int, input().split()))
_, F = int(input()), set(map(int, input().split()))
print(len(E.union(F)))