/*
Problem Statement: https://leetcode.com/problems/set-matrix-zeroes/
Time: O(m • n)
Space: O(1)
Author: Mohammed Shoaib, github.com/Mohammed-Shoaib
*/

class Solution {
public:
	void setZeroes(vector<vector<int>>& matrix) {
		int m = matrix.size(), n = matrix[0].size();
		bool row = find(matrix[0].begin(), matrix[0].end(), 0) != matrix[0].end();
		
		for (int i = 1; i < m; i++)
			for (int j = 0; j < n; j++)
				if (matrix[i][j] == 0)
					matrix[i][0] = matrix[0][j] = 0;
		
		for (int i = 1; i < m; i++)
			for (int j = n - 1; j >= 0; j--)
				if (matrix[i][0] == 0 || matrix[0][j] == 0)
					matrix[i][j] = 0;
		
		if (row)
			fill(matrix[0].begin(), matrix[0].end(), 0);
	}
};