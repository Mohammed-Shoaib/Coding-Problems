/*
Problem Statement: https://www.hackerrank.com/challenges/game-of-stones-1/problem
*/

#include <iostream>
#include <string>

using namespace std;

string gameOfStones(int n) {
    return (n % 7 < 2) ? "Second" : "First";
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        cout << gameOfStones(n) << endl;
    }
    return 0;
}