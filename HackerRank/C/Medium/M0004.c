/*
Problem Statement: https://www.hackerrank.com/challenges/printing-tokens-/problem
*/

#include <stdio.h>
#include <string.h>

int main() {
	char s[1000];
	fgets(s, sizeof(s), stdin);
	char* token = strtok(s, " ");
	
	while (token) {
		printf("%s\n", token);
		token = strtok(NULL, " ");
	}

	return 0;
}