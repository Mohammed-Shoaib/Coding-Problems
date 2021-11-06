// Problem Code: 1373D

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long long maximize_even(int n, vector<int>& a) {
	long long even, max_sum, sum;
	even = max_sum = sum = 0;

	for (int i = 0; i < n; i += 2)
		even += a[i];
	
	// kadane's algorithm
	for (int i = 0; i + 1 < n; i += 2) {
		sum -= a[i];
		sum += a[i + 1];
		sum = max(0LL, sum);
		max_sum = max(sum, max_sum);
	}
	sum = 0;
	for (int i = 1; i + 1 < n; i += 2) {
		sum += a[i];
		sum -= a[i + 1];
		sum = max(0LL, sum);
		max_sum = max(sum, max_sum);
	}

	return even + max_sum;
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
		cout << maximize_even(n, a) << endl;
	}
	return 0;
}