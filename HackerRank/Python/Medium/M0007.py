# Problem Statement: https://www.hackerrank.com/challenges/no-idea/problem

_, m = map(int, input().split())
n = map(int, input().split())
A = set(map(int, input().split()))
B = set(map(int, input().split()))
h = [1 if x in A else -1 if x in B else 0 for x in n]
print(sum(h))