/*
Problem Statement: https://www.hackerrank.com/challenges/halloween-sale/problem
*/

#include <iostream>

using namespace std;

int halloweenSale(int p, int d, int m, int s) {
    int games = 0;
    while (s >= p) {
        s -= p;
        p = max(p - d, m);
        games++;
    }
    return games;
}

int main() {
    int p, d, m, s;
    cin >> p >> d >> m >> s;
    cout << halloweenSale(p, d, m, s);
    return 0;
}