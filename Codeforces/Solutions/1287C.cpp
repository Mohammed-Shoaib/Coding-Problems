// Problem Code: 1287C

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int garland(int n, vector<int>& p) {
	int inf = 1e9;
	int dp[n + 1][n + 1][2];

	// Initialization
	for (int i = 0; i <= n; i++)
		for (int j = 0; j <= n; j++)
			dp[i][j][0] = dp[i][j][1] = inf;
	dp[0][0][0] = dp[0][0][1] = 0;
	
	// Dynamic Programming
	for (int i = 1; i <= n; i++)
		for (int j = 0; j <= i; j++) {
			if (p[i - 1] % 2 == 0)
				dp[i][j][0] = min(dp[i - 1][j - 1][0], dp[i - 1][j - 1][1] + 1);
			if (p[i - 1] % 2 || p[i - 1] == 0)
				dp[i][j][1] = min(dp[i - 1][j][0] + 1, dp[i - 1][j][1]);
		}

	return min(dp[n][n / 2][0], dp[n][n / 2][1]);
}

int main() {
	int n;
	cin >> n;
	vector<int> p(n);
	for (int i = 0; i < n; i++)
		cin >> p[i];
	cout << garland(n, p);
	return 0;
}