/*
Problem Statement: https://www.hackerrank.com/challenges/sherlock-and-the-beast/problem
*/

#include <iostream>
#include <string>

using namespace std;

string decentNumber(int n) {
	if (n % 3 == 0)
		return string(n, '5');
	int m = 5;
	while (m <= n) {
		if ((n - m) % 3 == 0)
			return string(n - m, '5') + string(m, '3');
		m += 5;
	}
	return "-1";
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		cout << decentNumber(n) << endl;
	}
	return 0;
}