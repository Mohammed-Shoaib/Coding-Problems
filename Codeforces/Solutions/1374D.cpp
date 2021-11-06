// Problem Code: 1374D

#include <iostream>
#include <vector>
#include <map>

using namespace std;

long long zero_remainder_array(int n, int k, vector<int>& a) {
	long long max_x = 0;
	map<int, long long> freq;

	for (int x: a)
		if (x % k != 0)
			freq[k - x % k]++;
	
	for (auto& [x, v]: freq)
		max_x = max(x + k * (v - 1) + 1, max_x);
	
	return max_x;
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n, k;
		cin >> n >> k;
		vector<int> a(n);
		for (int i = 0; i < n; i++)
			cin >> a[i];
		cout << zero_remainder_array(n, k, a) << endl;
	}
	return 0;
}