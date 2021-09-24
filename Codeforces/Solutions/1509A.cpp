/*
Problem Code: 1509A
Time: O(n)
Space: O(1)
Author: Mohammed Shoaib, github.com/Mohammed-Shoaib
*/

#include <iostream>
#include <vector>

using namespace std;

void average_height(int n, vector<int>& a) {
	for (int& x: a)
		if (x & 1)
			cout << x << " ";
	for (int& x: a)
		if (x % 2 == 0)
			cout << x << " ";
	cout << endl;
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		vector<int> a(n);
		for (int i = 0; i < n; i++)
			cin >> a[i];
		average_height(n, a);
	}
	return 0;
}