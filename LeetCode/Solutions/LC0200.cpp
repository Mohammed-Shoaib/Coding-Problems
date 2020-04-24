/*
Problem Statement: https://leetcode.com/problems/number-of-islands/
*/

class Solution {
public:
    int numIslands(vector<vector<char>> grid) {
		if (grid.empty())
			return 0;
		int n, m, components;
		n = grid.size();
		m = grid[0].size();
		components = 0;

		// flood-fill algorithm
		function<void(int, int)> flood_fill = [&](int i, int j) {
			if (i < 0 || i >= n || j < 0 || j >= m || grid[i][j] == '0')
				return;
			grid[i][j] = '0';
			flood_fill(i - 1, j);
			flood_fill(i + 1, j);
			flood_fill(i, j - 1);
			flood_fill(i, j + 1);
		};

		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				if (grid[i][j] == '1') {
					components++;
					flood_fill(i, j);
				}
		
		return components;
    }
};