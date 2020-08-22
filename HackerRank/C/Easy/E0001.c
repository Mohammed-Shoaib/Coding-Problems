/*
Problem Statement: https://www.hackerrank.com/challenges/hello-world-c/problem
*/

#include <stdio.h>

int main() {
	char s[100];
	fgets(s, sizeof(s), stdin);
	printf("Hello, World!\n%s", s);
	return 0;
}