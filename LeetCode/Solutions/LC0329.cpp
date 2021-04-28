/*
Problem Statement: https://leetcode.com/problems/longest-increasing-path-in-a-matrix/
Time: O(n • m)
Space: O(n • m)
Author: Mohammed Shoaib, github.com/Mohammed-Shoaib
*/

class Solution {
public:
	int longestIncreasingPath(vector<vector<int>>& matrix) {
		int m, n, max_depth;
		m = matrix.size();
		n = matrix[0].size();
		max_depth = 0;
		vector<vector<int>> cache(m, vector<int>(n, -1));
		
		// traverse directions easily
		vector<int> xdir = {-1, 0, 1, 0};
		vector<int> ydir = {0, -1, 0, 1};
		
		// helper function to check if a position is valid
		auto is_valid = [&](int x, int y) {
			return x >= 0 && x < m && y >= 0 && y < n;
		};
		
		// helper function to run dfs
		function<int(int, int)> dfs = [&](int x, int y) {
			int& depth = cache[x][y];
			if (depth != -1)
				return depth;
			depth = 1;
			
			for (int k = 0; k < xdir.size(); k++) {
				int new_x = x + xdir[k], new_y = y + ydir[k];
				if (is_valid(new_x, new_y) && matrix[x][y] < matrix[new_x][new_y])
					depth = max(1 + dfs(new_x, new_y), depth);
			}
			
			return depth;
		};
		
		// get the longest path
		for (int i = 0; i < m; i++)
			for (int j = 0; j < n; j++)
				max_depth = max(dfs(i, j), max_depth);
		
		return max_depth;
	}
};