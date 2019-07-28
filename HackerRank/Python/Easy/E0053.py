# Problem Statement: https://www.hackerrank.com/challenges/any-or-all/problem

_, N = input(), input().split()
c1 = [int(n) > 0 for n in N]
c2 = [n == n[::-1] for n in N]
print(all(c1) and any(c2))