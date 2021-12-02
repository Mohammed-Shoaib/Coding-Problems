// Problem Code: 1339C

#include <iostream>
#include <vector>
#include <limits>
#include <algorithm>

using namespace std;

int powered_addition(int n, vector<int>& a) {
	int T, max_a, max_d;
	T = max_d = 0;
	max_a = numeric_limits<int>::min();
	
	for (int& x: a) {
		max_a = max(x, max_a);
		max_d = max(max_a - x, max_d);
	}
	
	while (max_d) {
		max_d >>= 1;
		T++;
	}
	
	return T;
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
		cout << powered_addition(n, a) << endl;
	}
	return 0;
}