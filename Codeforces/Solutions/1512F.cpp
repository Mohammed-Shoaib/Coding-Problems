/*
Problem Code: 1512F
Time: O(n)
Space: O(1)
Author: Mohammed Shoaib, github.com/Mohammed-Shoaib
*/

#include <iostream>
#include <vector>
#include <limits>
#include <algorithm>

using namespace std;

int education(int n, int c, vector<int>& a, vector<int>& b) {
	int64_t min_days, days, coins;
	days = coins = 0;
	min_days = numeric_limits<int64_t>::max();
	
	for (int i = 0; i < n; i++) {
		// buy the computer without promotion
		int64_t need, d;
		need = c - coins;
		d = max((int64_t) 0, (need + a[i] - 1) / a[i]);
		min_days = min(d + days, min_days);
		
		// buy the computer with promotion
		if (i + 1 < n) {
			need = b[i] - coins;
			d = max((int64_t) 0, (need + a[i] - 1) / a[i]);
			coins += d * a[i] - b[i];
			days += 1 + d;
		}
	}
	
	return min_days;
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n, c;
		cin >> n >> c;
		vector<int> a(n), b(n - 1);
		for (int& x: a)
			cin >> x;
		for (int& x: b)
			cin >> x;
		cout << education(n, c, a, b) << endl;
	}
	return 0;
}