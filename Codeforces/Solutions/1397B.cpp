// Problem Code: 1397B

#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

int64_t power_sequence(int n, vector<int>& a) {
	int64_t min_cost = numeric_limits<int64_t>::max();
	sort(a.begin(), a.end());
	
	for (int b = 1; ; b++) {
		int64_t c = 1, cost = 0;
		for (int i = 0; i < n; i++) {
			if (c >= 1e15)
				return min_cost;
			cost += abs(a[i] - c);
			c *= b;
		}
		min_cost = min(cost, min_cost);
	}
	
	return -1;
}

int main() {
	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++)
		cin >> a[i];
	cout << power_sequence(n, a);	
	return 0;
}