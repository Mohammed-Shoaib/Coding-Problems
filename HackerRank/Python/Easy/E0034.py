# Problem Statement: https://www.hackerrank.com/challenges/symmetric-difference/problem

_, M = int(input()), set(map(int, input().split()))
_, N = int(input()), set(map(int, input().split()))
print(*sorted(M ^ N), sep='\n')