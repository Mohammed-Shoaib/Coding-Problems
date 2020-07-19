#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool same(int a, int b, int c, int d) {
	if (a == b)
		return c == d;
	else if (a < b)
		return c < d;
	else
		return c > d;
}

int alien_piano(int K, vector<int>& A) {
	vector<vector<int>> dp(K, vector<int>(4, numeric_limits<int>::max()));

	// initialization
	fill(dp[0].begin(), dp[0].end(), 0);

	// dynamic programming
	for (int i = 1; i < K; i++)
		for (int j = 0; j < 4; j++)
			for (int k = 0; k < 4; k++)
				dp[i][j] = min(dp[i - 1][k] + !same(A[i - 1], A[i], k, j), dp[i][j]);

	return *min_element(dp[K - 1].begin(), dp[K - 1].end());
}

int main() {
	int T;
	cin >> T;
	for (int x = 1; x <= T; x++) {
		int K;
		cin >> K;
		vector<int> A(K);
		for (int i = 0; i < K; i++)
			cin >> A[i];
		cout << "Case #" << x << ": " << alien_piano(K, A) << endl;
	}
	return 0;
}