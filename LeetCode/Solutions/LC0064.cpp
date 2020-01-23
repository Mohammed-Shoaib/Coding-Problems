/*
Problem Statement: https://leetcode.com/problems/minimum-path-sum/
*/

class Solution {
public:
    int minPathSum(vector< vector<int> >& grid) {
		int m, n;
		m = grid.size();
		n = grid[0].size();
		int dp[m][n];

		// Base Cases
		dp[0][0] = grid[0][0];
		for (int i = 1; i < m; i++)
			dp[i][0] = grid[i][0] + dp[i - 1][0];
		for (int i = 1; i < n; i++)
			dp[0][i] = grid[0][i] + dp[0][i - 1];
		
		// Dynamic Programming
		for (int i = 1; i < m; i++)
			for (int j = 1; j < n; j++)
				dp[i][j] = grid[i][j] + min(dp[i - 1][j], dp[i][j - 1]);
		
		return dp[m - 1][n - 1];
    }
};