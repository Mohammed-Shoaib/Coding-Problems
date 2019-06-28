# Problem Statement: https://www.hackerrank.com/challenges/triangle-quest-2/problem

# Python 2: No more than 2 lines
for i in range(1, int(input()) + 1):
	print(reduce(lambda x, y: x*10 + y, [1]*i)**2)