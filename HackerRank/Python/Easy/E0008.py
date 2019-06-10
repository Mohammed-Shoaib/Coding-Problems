# Problem Statement: https://www.hackerrank.com/challenges/nested-list/problem

N = int(input())
S = [[input(), float(input())] for _ in range(N)]
S = sorted(S, key=lambda s: (s[1], s[0]))
S = [s for s in S if s[1] != S[0][1]]
S = [s for s in S if s[1] == S[0][1]]
for s in S:	
	print(s[0])