/*
Problem Code: 1512A
Time: O(n)
Space: O(1)
Author: Mohammed Shoaib, github.com/Mohammed-Shoaib
*/

#include <iostream>
#include <vector>

using namespace std;

int spy_detected(int n, vector<int>& a) {
	for (int i = 1; i + 1 < n; i++)
		if (a[i - 1] != a[i])
			return i + (a[i] != a[i + 1]);
	return n;
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		vector<int> a(n);
		for (int& x: a)
			cin >> x;
		cout << spy_detected(n, a) << endl;
	}
	return 0;
}