/*
Problem Statement: https://www.hackerrank.com/challenges/printing-pattern-2/problem
*/

#include <stdio.h>
#include <stdlib.h>

int max(int a, int b) {
	return (a > b) ? a : b;
}

int main() {
	int n;
	scanf("%d", &n);
	
	for (int i = -n + 1; i < n; i++) {
		for (int j = -n + 1; j < n; j++)
			printf("%d ", max(abs(i), abs(j)) + 1);
		printf("\n");
	}

	return 0;
}