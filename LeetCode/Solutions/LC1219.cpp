/*
Problem Statement: https://leetcode.com/problems/path-with-maximum-gold/
Time: O(k • 3ᵏ)
Space: O(k)
k => Number of cells containing gold
Author: Mohammed Shoaib, github.com/Mohammed-Shoaib
*/

class Solution {
public:
	int getMaximumGold(vector<vector<int>>& grid) {
		int max_gold, m, n;
		max_gold = 0;
		m = grid.size();
		n = grid[0].size();
		
		// traverse directions easily
		vector<int> x = {-1, 0, 1, 0};
		vector<int> y = {0, -1, 0, 1};
		
		// helper function
		function<int(int, int)> dfs = [&](int i, int j) {
			// base cases
			if (i < 0 || i >= m || j < 0 || j >= n || grid[i][j] <= 0)
				return 0;
			
			// recurse
			int gold = 0;
			grid[i][j] *= -1;
			
			for(int k = 0; k < 4; k++)
				gold = max(dfs(i + y[k], j + x[k]), gold);
			
			grid[i][j] *= -1;
			
			return gold + grid[i][j];
		};
		
		for (int i = 0; i < m; i++)
			for (int j = 0; j < n; j++)
				max_gold = max(dfs(i, j), max_gold);
		
		return max_gold;
	}
};