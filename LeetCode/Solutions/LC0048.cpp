/*
Problem Statement: https://leetcode.com/problems/rotate-image/
Time: O(n²)
Space: O(1)
Author: Mohammed Shoaib, github.com/Mohammed-Shoaib
*/

class Solution {
public:
	void rotate(vector<vector<int>>& matrix) {
		int n = matrix.size();
		
		// reverse rows
		reverse(matrix.begin(), matrix.end());
		
		// transpose the matrix
		for (int i = 0; i < n; i++)
			for (int j = 0; j < i; j++)
				swap(matrix[i][j], matrix[j][i]);
	}
};