# Problem Statement: https://www.hackerrank.com/challenges/py-set-intersection-operation/problem

_, E = int(input()), set(map(int, input().split()))
_, F = int(input()), set(map(int, input().split()))
print(len(E.intersection(F)))