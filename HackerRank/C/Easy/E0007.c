/*
Problem Statement: https://www.hackerrank.com/challenges/for-loop-in-c/problem
*/

#include <stdio.h>

void number(int a, int b) {
    char* nums[] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};

    for (int i = a; i <= b; i++) {
        if (i <= 9)
            printf("%s\n", nums[i]);
        else
            printf("%s\n", (i & 1) ? "odd" : "even");
    }
}

int main() {
    int a, b;
    scanf("%d %d", &a, &b);
    number(a, b);
    return 0;
}