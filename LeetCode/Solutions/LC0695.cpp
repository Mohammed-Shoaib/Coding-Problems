/*
Problem Statement: https://leetcode.com/problems/max-area-of-island/
Time: O(m • n)
Space: O(m • n)
Author: Mohammed Shoaib, github.com/Mohammed-Shoaib
*/

class Solution {
public:
	int maxAreaOfIsland(vector<vector<int>>& grid) {
		int area, max_area = 0, m = grid.size(), n = grid[0].size();
		vector<vector<bool>> visited(m, vector<bool>(n));
		
		// traverse directions easily
		vector<int> xdir = {-1, 0, 1, 0};
		vector<int> ydir = {0, -1, 0, 1};
		
		// helper function
		function<void(int, int)> dfs = [&](int x, int y) {
			// base case
			if (x < 0 || x == m || y < 0 || y == n || grid[x][y] == 0 || visited[x][y])
				return;
			
			area++;
			visited[x][y] = true;
			
			for (int k = 0; k < xdir.size(); k++) {
				int new_x = x + xdir[k], new_y = y + ydir[k];
				dfs(new_x, new_y);
			}
		};
		
		for (int i = 0; i < m; i++)
			for (int j = 0; j < n; j++)
				if (!visited[i][j]) {
					area = 0;
					dfs(i, j);
					max_area = max(area, max_area);
				}
		
		return max_area;
	}
};