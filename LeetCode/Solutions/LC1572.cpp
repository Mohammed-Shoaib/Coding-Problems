/*
Problem Statement: https://leetcode.com/problems/matrix-diagonal-sum/
Time: O(n)
Space: O(1)
Author: Mohammed Shoaib, github.com/Mohammed-Shoaib
*/

class Solution {
public:
	int diagonalSum(vector<vector<int>>& mat) {
		int sum = 0, n = mat.size();
		
		for (int i = 0; i < n; i++)
			sum += mat[i][i] + mat[i][n - i - 1];
		if (n & 1)
			sum -= mat[n / 2][n / 2];
		
		return sum;
	}
};