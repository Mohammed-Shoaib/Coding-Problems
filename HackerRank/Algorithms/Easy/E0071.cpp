/*
Problem Statement: https://www.hackerrank.com/challenges/chocolate-feast/problem
*/

#include <iostream>

using namespace std;

int chocolateFeast(int n, int c, int m) {
	int bars, wrappers;
	bars = wrappers = n / c;
	while (wrappers >= m) {
		wrappers -= m;
		wrappers++;
		bars++;
	}
	return bars;
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n, c, m;
		cin >> n >> c >> m;
		cout << chocolateFeast(n, c, m) << endl;
	}
	return 0;
}