# Problem Statement: https://www.hackerrank.com/challenges/collections-counter/problem

from collections import Counter

X = int(input())
counts = Counter(map(int, input().split()))
income = 0

for _ in range(int(input())):
    shoe_size, x = map(int, input().split())
    if counts[shoe_size] > 0:
        income += x
        counts[shoe_size] -= 1

print(income)