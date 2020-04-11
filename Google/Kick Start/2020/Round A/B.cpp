#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int plates(int N, int K, int P, vector<vector<int>>& st) {
	int dp[N + 1][P + 1] = {}, prefix[N + 1][K + 1] = {};

	// prefix sum array
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= K; j++)
			prefix[i][j] = st[i - 1][j - 1] + prefix[i][j - 1];

	// dynamic programming
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= P; j++)
			for (int k = 0; k <= min(j, K); k++)
				dp[i][j] = max(prefix[i][k] + dp[i - 1][j - k], dp[i][j]);
	
	return dp[N][P];
}

int main() {
	int T;
	cin >> T;
	for (int x = 1; x <= T; x++) {
		int N, K, P;
		cin >> N >> K >> P;
		vector<vector<int>> st(N, vector<int>(K));
		for (int i = 0; i < N; i++)
			for (int j = 0; j < K; j++)
				cin >> st[i][j];
		cout << "Case #" << x << ": " << plates(N, K, P, st) << endl;
	}
	return 0;
}