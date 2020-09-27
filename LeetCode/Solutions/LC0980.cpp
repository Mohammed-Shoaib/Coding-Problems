/*
Problem Statement: https://leetcode.com/problems/unique-paths-iii/
Time: O(3ᵐ ˙ ⁿ)
Space: O(m • n)
Author: Mohammed Shoaib, github.com/Mohammed-Shoaib
*/

class Solution {
public:
	int uniquePathsIII(vector<vector<int>>& grid) {
		int m, n, paths, empty;
		m = grid.size();
		n = grid[0].size();
		paths = empty = 0;
		pair<int, int> start;
		
		// traverse directions easily
		vector<int> xdir = {-1, 0, 1, 0};
		vector<int> ydir = {0, -1, 0, 1};
		
		// helper function to count paths
		function<void(int, int, int)> dfs = [&](int x, int y, int len) {
			if (x < 0 || x == m || y < 0 || y == n || grid[x][y] == -1)
				return;
			else if (grid[x][y] == 2) {
				paths += empty == len - 1;
				return;
			}
			
			grid[x][y] = -1;
			for (int k = 0; k < xdir.size(); k++) {
				int new_x = x + xdir[k], new_y = y + ydir[k];
				dfs(new_x, new_y, len + 1);			
			}
			grid[x][y] = 0;
		};
		
		for (int i = 0; i < m; i++)
			for (int j = 0; j < n; j++) {
				if (grid[i][j] == 1)
					start = {i, j};
				else if (grid[i][j] == 0)
					empty++;
			}
		dfs(start.first, start.second, 0);
		
		return paths;
	}
};