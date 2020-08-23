// Problem Code: A1

#include <iostream>
#include <vector>

using namespace std;

string subsetSum(vector<int> coins, int n, int m) {
	vector< vector<bool> > dp(n + 1, vector<bool>(m + 1));

	for (int i=0 ; i <= n ; i++)
		dp[i][0] = true;
	
	for (int i=1 ; i <= n ; i++)
		for (int j=1 ; j <= m ; j++) {
			dp[i][j] = dp[i - 1][j];
			if (j >= coins[i - 1])
				dp[i][j] = dp[i][j] || dp[i - 1][j - coins[i - 1]];
		}

	return (dp[n][m]) ? "Yes" : "No";
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n, m;
		cin >> n >> m;
		vector<int> coins(n);
		for (int i=0 ; i < n ; i++)
			cin >> coins[i];
		cout << subsetSum(coins, n, m) << endl;
	}
	return 0;
}