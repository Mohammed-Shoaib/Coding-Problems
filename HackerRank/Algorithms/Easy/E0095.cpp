/*
Problem Code: https://www.hackerrank.com/challenges/append-and-delete/problem
*/

#include <iostream>
#include <string>
#include <iterator>
#include <algorithm>

using namespace std;

string appendAndDelete(string &s, string &t, int k) {
	if (s.length() + t.length() <= k)
		return "Yes";
	auto it = mismatch(s.begin(), s.end(), t.begin());
	int min_op = distance(it.first, s.end()) + distance(it.second, t.end());
	return (k < min_op || (k - min_op) & 1) ? "No" : "Yes";
}

int main() {
	string s, t;
	int k;
	cin >> s >> t >> k;
	cout << appendAndDelete(s, t, k);
	return 0;
}