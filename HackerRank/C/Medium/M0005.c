/*
Problem Statement: https://www.hackerrank.com/challenges/frequency-of-digits-1/problem
*/

#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main() {
	int freq[10] = {0};
	char num[1000];
	fgets(num, sizeof(num), stdin);

	for (int i = 0; i < strlen(num); i++)
		if (isdigit(num[i]))
			freq[num[i] - '0']++;
	
	for (int i = 0; i < 10; i++)
		printf("%d ", freq[i]);

	return 0;
}