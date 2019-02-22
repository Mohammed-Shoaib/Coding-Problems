/*
Problem Statement: https://www.hackerrank.com/challenges/tower-breakers-1/problem
*/

#include <iostream>

using namespace std;

int towerBreakers(int n, int m) {
    return (n % 2 == 0 || m == 1) ? 2 : 1;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        cout << towerBreakers(n, m) << endl;
    }
    return 0;
}