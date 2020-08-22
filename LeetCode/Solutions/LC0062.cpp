/*
Problem Statement: https://leetcode.com/problems/unique-paths/
Time: O(m • n)
Space: O(m • n)
Author: Mohammed Shoaib, github.com/Mohammed-Shoaib
*/

class Solution {
public:
	int uniquePaths(int m, int n) {
		int dp[m][n];
		
		// dynamic programming
		for (int i = 0; i < m; i++)
			for (int j = 0; j < n; j++) {
				if (i == 0 || j == 0)
					dp[i][j] = 1;
				else
					dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
			}
		
		return dp[m - 1][n - 1];
	}
};