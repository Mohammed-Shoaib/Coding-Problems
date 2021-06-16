/*
Problem Statement: https://leetcode.com/problems/transpose-matrix/
Time: O(m • n)
Space: O(m • n)
Author: Mohammed Shoaib, github.com/Mohammed-Shoaib
*/

class Solution {
public:
	vector<vector<int>> transpose(vector<vector<int>>& matrix) {
		int m = matrix.size(), n = matrix[0].size();
		vector<vector<int>> grid(n, vector<int>(m));
		
		for (int i = 0; i < m; i++)
			for (int j = 0; j < n; j++)
				grid[j][i] = matrix[i][j];
		
		return grid;
	}
};