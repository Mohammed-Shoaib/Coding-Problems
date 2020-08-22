/*
Problem Statement: https://www.hackerrank.com/challenges/sum-of-digits-of-a-five-digit-number/problem
*/

#include <stdio.h>

int sum_digits(int n) {
	int sum = 0;
	while (n != 0) {
		sum += n % 10;
		n /= 10;
	}
	return sum;
}

int main() {
	int n;
	scanf("%d", &n);
	printf("%d", sum_digits(n));
	return 0;
}