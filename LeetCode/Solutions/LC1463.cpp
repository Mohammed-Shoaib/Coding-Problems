/*
Problem Statement: https://leetcode.com/problems/cherry-pickup-ii/
*/

class Solution {
public:
	int cherryPickup(vector<vector<int>>& grid) {
		int m, n;
		m = grid.size();
		n = grid[0].size();
		vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(n, -1)));

		// helper function
		function<bool(int, int)> valid = [&](int r, int c) {
			return r >= 0 && r < m && c >= 0 && c < n;
		};

		// top-down dynamic programming
		function<int(int, int, int)> state = [&](int r, int c1, int c2) {
			// base cases
			if (!valid(r, c1) || !valid(r, c2))
				return 0;
			else if (dp[r][c1][c2] != -1)
				return dp[r][c1][c2];
			
			int cherries = 0;
			for (int x1 = -1; x1 <= 1; x1++)
				for (int x2 = -1; x2 <= 1; x2++)
					cherries = max(state(r + 1, c1 + x1, c2 + x2), cherries);
			cherries += grid[r][c1];
			if (c1 != c2)
				cherries += grid[r][c2];

			return dp[r][c1][c2] = cherries;
		};

		return state(0, 0, n - 1);
	}
};