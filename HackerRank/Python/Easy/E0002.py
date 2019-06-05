# Problem Statement: https://www.hackerrank.com/challenges/py-if-else/problem

n = int(input())

if n & 1 or n in range(6, 21):
	print("Weird")
else:
	print("Not Weird")