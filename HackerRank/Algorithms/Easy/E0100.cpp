/*
Problem Statement: https://www.hackerrank.com/challenges/nim-game-1/problem
*/

#include <iostream>
#include <vector>
#include <numeric>
#include <functional>

using namespace std;

string nimGame(vector<int> &pile) {
    int winner = accumulate(pile.begin(), pile.end(), 0, bit_xor<int>());
    return winner ? "First" : "Second";
}

int main() {
    int g;
    cin >> g;
    while (g--) {
        int n;
        cin >> n;
        vector<int> pile(n);
        for (int i = 0; i < n; i++)
            cin >> pile[i];
        cout << nimGame(pile) << endl;
    }
	return 0;
}