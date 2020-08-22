# Problem Statement: https://www.hackerrank.com/challenges/py-introduction-to-sets/problem

def average(array):
	S = set(array)
	return sum(S) / len(S)