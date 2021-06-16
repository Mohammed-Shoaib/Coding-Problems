/*
Problem Statement: https://leetcode.com/problems/image-smoother/
Time: O(m • n)
Space: O(m • n)
Author: Mohammed Shoaib, github.com/Mohammed-Shoaib
*/

class Solution {
public:
	vector<vector<int>> imageSmoother(vector<vector<int>>& M) {
		int m = M.size(), n = M[0].size();
		vector<vector<int>> grid(m, vector<int>(n));
		
		for (int i = 0; i < m; i++)
			for (int j = 0; j < n; j++) {
				int cnt = 0;
				for (int x = i - 1; x <= i + 1; x++)
					for (int y = j - 1; y <= j + 1; y++)
						if (x >= 0 && x < m && y >= 0 && y < n) {
							cnt++;
							grid[i][j] += M[x][y];
						}
				grid[i][j] /= cnt;
			}
		
		return grid;
	}
};