/*
Problem Statement: https://www.hackerrank.com/challenges/nimble-game-1/problem
*/

#include <iostream>
#include <vector>

using namespace std;

string nimbleGame(vector<int> &c) {
    int winner = 0;
    for (int i = 1; i < c.size(); i++)
        if (c[i] & 1)
            winner ^= i;
    return winner ? "First" : "Second";
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<int> c(n);
        for (int i = 0; i < n; i++)
            cin >> c[i];
        cout << nimbleGame(c) << endl;
    }
}