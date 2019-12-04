/*
Problem Statement: https://www.hackerrank.com/challenges/recursion-in-c/problem
*/

#include <stdio.h>

int find_nth_term(int n, int a, int b, int c) {
    if (n == a)
        return 1;
    else if (n == b)
        return 2;
    else if (n == c)
        return 3;
    else
        return find_nth_term(n - 1, a, b, c) + find_nth_term(n - 2, a, b, c) + find_nth_term(n - 3, a, b, c);
}

int main() {
    int n, a, b, c;
    scanf("%d %d %d %d", &n, &a, &b, &c);
    printf("%d", find_nth_term(n, a, b, c));
    return 0;
}