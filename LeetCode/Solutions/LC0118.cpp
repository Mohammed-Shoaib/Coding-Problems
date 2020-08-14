/*
Problem Statement: https://leetcode.com/problems/pascals-triangle/
Time: O(n²)
Space: O(n²)
Author: Mohammed Shoaib, github.com/Mohammed-Shoaib
*/

class Solution {
public:
	vector<vector<int>> generate(int numRows) {
		vector<vector<int>> rows(numRows);
		for (int i = 0; i < numRows; ++i) {
			rows[i] = vector<int>(i + 1, 1);
			for (int j = 1; j < i; j++)
				rows[i][j] = rows[i - 1][j - 1] + rows[i - 1][j];
		}
		return rows;
	}
};