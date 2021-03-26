/*
Problem Statement: https://leetcode.com/problems/search-a-2d-matrix-ii/
Time: O(m + n)
Space: O(1)
Author: Mohammed Shoaib, github.com/Mohammed-Shoaib
*/

class Solution {
public:
	bool searchMatrix(vector<vector<int>>& matrix, int target) {
		int m = matrix.size(), n = matrix[0].size();
		int x = 0, y = n - 1;
		
		while (x < m && y >= 0) {
			if (matrix[x][y] == target)
				return true;
			else if (matrix[x][y] < target)
				x++;
			else
				y--;
		}
		
		return false;
	}
};