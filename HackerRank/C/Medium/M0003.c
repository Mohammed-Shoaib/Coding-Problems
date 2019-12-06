/*
Problem Statement: https://www.hackerrank.com/challenges/reverse-array-c/problem
*/

#include <stdio.h>

void swap(int* a, int* b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

int main() {
	int n;
	scanf("%d", &n);
	int arr[n];
	
	for (int i = 0; i < n; i++)
		scanf("%d", arr + i);
	for (int i = 0; i < n >> 1; i++)
		swap(&arr[i], &arr[n - i - 1]);
	for (int i = 0; i < n; i++)
		printf("%d ", arr[i]);

	return 0;
}