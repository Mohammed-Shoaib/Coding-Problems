/*
Problem Statement: https://www.hackerrank.com/challenges/variable-sized-arrays/problem
*/

#include <iostream>
#include <vector>

using namespace std;

int main() {
	int n, q;
	cin >> n >> q;
	vector< vector<int> > a(n, vector<int>());
	for (int i = 0; i < n; i++) {
		int len, num;
		cin >> len;
		for (int j = 0; j < len; j++) {
			cin >> num;
			a[i].push_back(num);
		}
	}
	while (q--) {
		int i, j;
		cin >> i >> j;
		cout << a[i][j] << endl;
	}
	return 0;
}