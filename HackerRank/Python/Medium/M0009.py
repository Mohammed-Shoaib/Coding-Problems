# Problem Statement: https://www.hackerrank.com/challenges/python-quest-1/problem

# Python 2: No more than 2 lines
for i in range(1, int(input())):
	print(reduce(lambda x, y: x*10 + y, [i]*i))