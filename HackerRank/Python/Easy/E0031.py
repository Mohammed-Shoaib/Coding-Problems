# Problem Statement: https://www.hackerrank.com/challenges/exceptions/problem

for _ in range(int(input())):
	try:
		a, b = map(int, input().split())
		print(a // b)
	except (ZeroDivisionError, ValueError) as e:
		print(f'Error Code: {e}')