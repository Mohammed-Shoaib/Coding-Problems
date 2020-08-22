/*
Problem Statement: https://www.hackerrank.com/challenges/functions-in-c/problem
*/

#include <stdio.h>

int max(int a, int b) {
	return (a > b) ? a : b;
}

int max_of_four(int a, int b, int c, int d) {
	return max(max(a, b), max(c, d));
}

int main() {
	int a, b, c, d;
	scanf("%d %d %d %d", &a, &b, &c, &d);
	printf("%d", max_of_four(a, b, c, d));
	return 0;
}