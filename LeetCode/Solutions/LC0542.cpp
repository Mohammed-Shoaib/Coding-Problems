/*
Problem Statement: https://leetcode.com/problems/01-matrix/
Time: O(m • n)
Space: O(m • n)
Author: Mohammed Shoaib, github.com/Mohammed-Shoaib
*/

class Solution {
public:
	vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
		int m = matrix.size(), n = matrix[0].size();
		vector<vector<int>> dp(m, vector<int>(n, 1e9));
		
		// dynamic programming, move right or down
		for (int i = 0; i < m; i++)
			for (int j = 0; j < n; j++) {
				if (matrix[i][j] == 0)
					dp[i][j] = 0;
				if (i > 0)
					dp[i][j] = min(1 + dp[i - 1][j], dp[i][j]);
				if (j > 0)
					dp[i][j] = min(1 + dp[i][j - 1], dp[i][j]);
			}
		
		// dynamic programming, move up or left
		for (int i = m - 1; i >= 0; i--)
			for (int j = n - 1; j >= 0; j--) {
				if (i < m - 1)
					dp[i][j] = min(1 + dp[i + 1][j], dp[i][j]);
				if (j < n - 1)
					dp[i][j] = min(1 + dp[i][j + 1], dp[i][j]);
			}
		
		return dp;
	}
};