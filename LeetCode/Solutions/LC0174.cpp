/*
Problem Statement: https://leetcode.com/problems/dungeon-game/
*/

class Solution {
public:
	int calculateMinimumHP(vector<vector<int>>& dungeon) {
		int m, n;
		m = dungeon.size();
		n = dungeon[0].size();
		int dp[m][n];

		// initialization
		dp[m - 1][n - 1] = min(0, dungeon[m - 1][n - 1]);
		for (int i = m - 2; i >= 0; i--)
			dp[i][n - 1] = min(0, dungeon[i][n - 1] + dp[i + 1][n - 1]);
		for (int i = n - 2; i >= 0; i--)
			dp[m - 1][i] = min(0, dungeon[m - 1][i] + dp[m - 1][i + 1]);
		
		// dynamic programming
		for (int i = m - 2; i >= 0; i--)
			for (int j = n - 2; j >= 0; j--)
				dp[i][j] = min(0, dungeon[i][j] + max(dp[i + 1][j], dp[i][j + 1]));

		return abs(dp[0][0]) + 1;
	}
};