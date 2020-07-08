/*
Problem Statement: https://leetcode.com/problems/island-perimeter/
Time: O(m • n)
Space: O(1)
Author: Mohammed Shoaib, github.com/Mohammed-Shoaib
*/

class Solution {
public:
	int islandPerimeter(vector<vector<int>>& grid) {
		int m, n, len;
		m = grid.size();
		n = grid[0].size();
		len = 0;

		for (int i = 0; i < m; i++)
			for (int j = 0; j < n; j++)
				if (grid[i][j]) {
					len += 4;
					len -= 2 * (i > 0 && grid[i - 1][j]);
					len -= 2 * (j > 0 && grid[i][j - 1]);
				}
		
		return len;
	}
};