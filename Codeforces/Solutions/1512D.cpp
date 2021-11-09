/*
Problem Code: 1512D
Time: O(n)
Space: O(n)
Author: Mohammed Shoaib, github.com/Mohammed-Shoaib
*/

#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

void corrupted_array(int n, vector<int>& b) {
	int64_t sum = accumulate(b.begin(), b.end(), 0LL);
	vector<int> a;
	nth_element(b.begin(), b.begin() + 1, b.end(), greater<int>());
	
	sum -= b[0];
	for (int i = 1; i < n + 2; i++) {
		if (sum - b[i] != b[0])
			continue;
		for (int j = 1; j < n + 2; j++)
			if (i != j)
				a.push_back(b[j]);
		break;
	}
	sum += b[0];
	
	if (a.empty()) {
		sum = accumulate(b.begin() + 2, b.end(), 0LL);
		if (sum != b[1])
			a.push_back(-1);
		else {
			for (int i = 2; i < n + 2; i++)
				a.push_back(b[i]);
		}
	}
	
	for (int& x: a)
		cout << x << " ";
	cout << endl;
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		vector<int> b(n + 2);
		for (int& x: b)
			cin >> x;
		corrupted_array(n, b);
	}
	return 0;
}