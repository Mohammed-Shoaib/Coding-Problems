/*
Problem Statement: https://leetcode.com/problems/rotting-oranges/
Time: O(m • n)
Space: O(m • n)
Author: Mohammed Shoaib, github.com/Mohammed-Shoaib
*/

class Solution {
public:
	int orangesRotting(vector<vector<int>>& grid) {
		int min, fresh, m, n;
		min = fresh = 0;
		m = grid.size();
		n = grid[0].size();
		queue<pair<int, int>> q;
		
		// traverse directions easily
		vector<int> xdir = {-1, 0, 1, 0};
		vector<int> ydir = {0, -1, 0, 1};
		
		// helper function
		auto is_valid = [&](int x, int y) {
			return x >= 0 && x < m && y >= 0 && y < n;
		};
		
		// initialization
		for (int i = 0; i < m; i++)
			for (int j = 0; j < n; j++) {
				if (grid[i][j] == 2)
					q.push({i, j});
				else if (grid[i][j] == 1)
					fresh++;
			}
		
		// BFS
		while (!q.empty()) {
			int size = q.size();
			while (size--) {
				int x, y;
				tie(x, y) = q.front();
				q.pop();
				for (int k = 0; k < xdir.size(); k++) {
					int new_x = x + xdir[k], new_y = y + ydir[k];
					if (is_valid(new_x, new_y) && grid[new_x][new_y] == 1) {
						fresh--;
						grid[new_x][new_y] = 2;
						q.push({new_x, new_y});
					}
				}
			}
			min++;
		}
		
		return fresh ? -1 : max(0, min - 1);
	}
};