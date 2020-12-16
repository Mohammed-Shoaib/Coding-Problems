/*
Problem Statement: https://leetcode.com/problems/toeplitz-matrix/
Time: O(m • n)
Space: O(1)
Author: Mohammed Shoaib, github.com/Mohammed-Shoaib
*/

class Solution {
public:
	bool isToeplitzMatrix(vector<vector<int>>& matrix) {
		int m = matrix.size(), n = matrix[0].size();
		
		for (int i = 1; i < m; i++)
			for (int j = 1; j < n; j++)
				if (matrix[i - 1][j - 1] != matrix[i][j])
					return false;
		
		return true;
	}
};