/*
Problem Statement: https://leetcode.com/problems/unique-paths-ii/
Time Complexity: O(mn)
Space Complexity: O(mn)
*/

class Solution {
public:
	int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
		int m, n;
		m = obstacleGrid.size();
		n = obstacleGrid[0].size();
		vector<vector<int>> dp(m, vector<int>(n));

		// initialization
		for (int i = 0; i < m && !obstacleGrid[i][0]; i++)
			dp[i][0] = 1;
		for (int i = 0; i < n && !obstacleGrid[0][i]; i++)
			dp[0][i] = 1;

		// dynamic programming
		for (int i = 1; i < m; i++)
			for (int j = 1; j < n; j++)
				if (!obstacleGrid[i][j])
					dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
		
		return dp[m - 1][n - 1];
	}
};