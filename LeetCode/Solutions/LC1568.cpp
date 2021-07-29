/*
Problem Statement: https://leetcode.com/problems/minimum-number-of-days-to-disconnect-island/
Time: O((m • n)²)
Space: O(m • n)
Author: Mohammed Shoaib, github.com/Mohammed-Shoaib
*/

class Solution {
private:
	int m, n;
	
	// traverse directions easily
	vector<int> xdir = {-1, 0, 1, 0};
	vector<int> ydir = {0, -1, 0, 1};
	
	bool is_valid(int x, int y) {
		return (x >= 0 && x < m && y >= 0 && y < n);
	}
	
	void flood_fill(int x, int y, vector<vector<int>>& grid, vector<vector<bool>>& visited) {
		visited[x][y] = true;
		for (int k = 0; k < xdir.size(); k++) {
			int new_x = x + xdir[k], new_y = y + ydir[k];
			if (is_valid(new_x, new_y) && grid[new_x][new_y] && !visited[new_x][new_y])
				flood_fill(new_x, new_y, grid, visited);
		}
	};
	
	bool is_disconnected(vector<vector<int>>& grid) {
		int components = 0;
		vector<vector<bool>> visited(m, vector<bool>(n));
		
		// flood-fill algorithm
		for (int x = 0; x < m; x++)
			for (int y = 0; y < n; y++)
				if (grid[x][y] && !visited[x][y]) {
					if (++components > 1)
						return true;
					flood_fill(x, y, grid, visited);
				}
		
		return components == 0;
	}
	
public:
	int minDays(vector<vector<int>>& grid) {
		m = grid.size();
		n = grid[0].size();
		
		if (is_disconnected(grid))
			return 0;
		
		for (int x = 0; x < m; x++)
			for (int y = 0; y < n; y++) {
				if (grid[x][y] == 0)
					continue;
				grid[x][y] = 0;
				bool found = is_disconnected(grid);
				grid[x][y] = 1;
				if (found)
					return 1;
			}
		
		return 2;
	}
};