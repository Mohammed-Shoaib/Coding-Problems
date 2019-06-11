# Problem Statement: https://www.hackerrank.com/challenges/python-tuples/problem

n = int(input())
t = tuple(map(int, input().split()))
print(hash(t))