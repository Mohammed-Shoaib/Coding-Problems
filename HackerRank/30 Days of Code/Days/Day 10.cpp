/*
Problem Statement: https://www.hackerrank.com/challenges/30-binary-numbers/problem
*/

#include <iostream>
#include <algorithm>

using namespace std;

int binary(int n) {
    int max_ones, ones;
    max_ones = ones = 0;
    while (n) {
        ones = (n % 2) ? ones + 1 : 0;
        max_ones = max(ones, max_ones);
        n >>= 1;
    }
    return max_ones;
}

int main() {
    int n;
    cin >> n;
    cout << binary(n);
    return 0;
}