/*
Problem Statement: https://www.hackerrank.com/challenges/conditional-statements-in-c/problem
*/

#include <stdio.h>

char* number(int n) {
	char* nums[] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
	if (n <= 9)
		return nums[n];
	else
		return "Greater than 9";
}

int main() {
	int n;
	scanf("%d", &n);
	printf("%s", number(n));
	return 0;
}