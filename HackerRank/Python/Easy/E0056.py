# Problem Statement: https://www.hackerrank.com/challenges/map-and-lambda-expression/problem

cube = lambda x: x**3

def fibonacci(n):
	fib = [0, 1]
	for i in range(2, n):
		fib.append(fib[i - 1] + fib[i - 2])
	return fib[0:n]