/*
Problem Statement: https://www.hackerrank.com/challenges/poker-nim-1/problem
*/

#include <iostream>
#include <vector>
#include <numeric>
#include <functional>

using namespace std;

string pokerNim(vector<int> &c) {
    int winner = accumulate(c.begin(), c.end(), 0, bit_xor<int>());
    return winner ? "First" : "Second";
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n, k;
        cin >> n >> k;
        vector<int> c(n);
        for (int i = 0; i < n; i++)
            cin >> c[i];
        cout << pokerNim(c) << endl;
    }
	return 0;
}