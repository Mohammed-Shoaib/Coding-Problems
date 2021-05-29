// Problem Code: 1527C

#include <iostream>
#include <vector>
#include <map>

using namespace std;

int64_t sequence_pair_weight(int n, vector<int>& a) {
	int64_t sum = 0;
	map<int, int64_t> mp;
	vector<int64_t> dp(n + 1);
	
	for (int i = 1; i <= n; i++) {
		dp[i] = dp[i - 1] + mp[a[i - 1]];
		mp[a[i - 1]] += i;
		sum += dp[i];
	}
	
	return sum;
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
		cout << sequence_pair_weight(n, a) << endl;
	}
	return 0;
}