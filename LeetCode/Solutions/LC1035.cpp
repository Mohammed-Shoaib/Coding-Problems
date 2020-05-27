/*
Problem Statement: https://leetcode.com/problems/uncrossed-lines/
*/

class Solution {
public:
	int maxUncrossedLines(vector<int>& A, vector<int>& B) {
		int m, n;
		m = A.size();
		n = B.size();
		vector<vector<int>> dp(m + 1, vector<int>(n + 1));

		// dynamic programming
		for (int i = 1; i <= m; i++)
			for (int j = 1; j <= n; j++) {
				if (A[i - 1] == B[j - 1])
					dp[i][j] = 1 + dp[i - 1][j - 1];
				else
					dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
			}
		
		return dp[m][n];
	}
};