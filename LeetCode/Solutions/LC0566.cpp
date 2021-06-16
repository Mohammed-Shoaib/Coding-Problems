/*
Problem Statement: https://leetcode.com/problems/reshape-the-matrix/
Time: O(m • n)
Space: O(m • n)
Author: Mohammed Shoaib, github.com/Mohammed-Shoaib
*/

class Solution {
public:
	vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
		int m = mat.size(), n = mat[0].size();
		
		if (m * n != r * c)
			return mat;
		vector<vector<int>> grid(r, vector<int>(c));
		
		for (int i = 0, k = 0; i < m; i++)
			for (int j = 0; j < n; j++, k++)
				grid[k / c][k % c] = mat[i][j];
		
		return grid;
	}
};