/*
Problem Statement: https://www.hackerrank.com/challenges/pointer-in-c/problem
*/

#include <stdio.h>
#include <stdlib.h>

void update(int* a, int* b) {
	int diff = abs(*a - *b);
	*a += *b;
	*b = diff;
}

int main() {
	int a, b;
	scanf("%d %d", &a, &b);
	update(&a, &b);
	printf("%d\n%d", a, b);
	return 0;
}