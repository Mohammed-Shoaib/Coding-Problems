# Problem Statement: https://www.hackerrank.com/challenges/designer-door-mat/problem

N, M = map(int, input().split())

# Top
for i in range(1, N, 2):
	print(('.|.' * i).center(M, '-'))

# Message
print('WELCOME'.center(M, '-'))

# Bottom
for i in reversed(range(1, N, 2)):
	print(('.|.' * i).center(M, '-'))