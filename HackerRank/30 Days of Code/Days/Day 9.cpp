/*
Problem Statement: https://www.hackerrank.com/challenges/30-recursion/problem
*/

#include <iostream>

using namespace std;

int factorial(int N) {
    if (N == 1)
        return 1;
    else
        return N * factorial(N - 1);
}

int main() {
    int N;
    cin >> N;
    cout << factorial(N);
    return 0;
}