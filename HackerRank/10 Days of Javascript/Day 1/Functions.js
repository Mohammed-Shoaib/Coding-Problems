// Problem Statement: https://www.hackerrank.com/challenges/js10-function/problem

function factorial(n) {
	if (n === 1)
		return n;
	else
		return n * factorial(n - 1);
}