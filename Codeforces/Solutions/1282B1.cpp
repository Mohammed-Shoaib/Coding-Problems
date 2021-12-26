// Problem Code: 1282B1

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int buy_goods(int n, int p, int k, vector<int>& a) {
	int g = 0;
	vector<int> dp(n + 1);
	sort(a.begin(), a.end());

	// Initialize
	dp[0] = p;
	for (int i = 1; i < k && dp[i - 1] >= a[i]; g = i++)
		dp[i] = dp[i - 1] - a[i];

	// Dynamic Programming
	for (int i = k; i <= n; i++)
		if (dp[i - k] >= a[i]) {
			dp[i] = dp[i - k] - a[i];
			g = i;
		}

	return g;
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n, p, k;
		cin >> n >> p >> k;
		vector<int> a(n + 1);
		for (int i = 1; i <= n; i++)
			cin >> a[i];
		cout << buy_goods(n, p, k, a) << endl;
	}	
	return 0;
}