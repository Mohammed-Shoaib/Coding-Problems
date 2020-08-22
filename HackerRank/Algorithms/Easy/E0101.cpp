/*
Problem Statement: https://www.hackerrank.com/challenges/misere-nim-1/problem
*/

#include <iostream>
#include <vector>
#include <numeric>
#include <functional>
#include <algorithm>

using namespace std;

string misereNim(vector<int> &s) {
	int winner = accumulate(s.begin(), s.end(), 0, bit_xor<int>());
	bool flip = find_if(s.begin(), s.end(), [](int i) { return i != 1; }) == s.end();
	return (winner ^ flip) ? "First" : "Second";
}

int main() {
	int T;
	cin >> T;
	while (T--) {
		int n;
		cin >> n;
		vector<int> s(n);
		for (int i = 0; i < n; i++)
			cin >> s[i];
		cout << misereNim(s) << endl;
	}
	return 0;
}