/*
Problem Statement: https://leetcode.com/problems/range-sum-query-2d-immutable/
Space: O(m • n)
Author: Mohammed Shoaib, github.com/Mohammed-Shoaib

|-----------------------------------|----------|-------|
| Operations                        | Time     | Space |
|-----------------------------------|----------|-------|
| NumMatrix(matrix)                 | O(m • n) | O(1)  |
| sumRegion(row1, col1, row2, col2) | O(1)     | O(1)  |
|-----------------------------------|----------|-------|
*/

class NumMatrix {
private:
	vector<vector<int>> prefix;
public:
	NumMatrix(vector<vector<int>>& matrix) {
		// base case
		if (matrix.empty())
			return;
		
		int m = matrix.size(), n = matrix[0].size();
		prefix = vector<vector<int>>(m + 1, vector<int>(n + 1));
		
		// 2-dimensional prefix sum
		for (int i = 0; i < m; i++)
			for (int j = 0; j < n; j++)
				prefix[i + 1][j + 1] = matrix[i][j]
					+ prefix[i + 1][j]
					+ prefix[i][j + 1]
					- prefix[i][j];
	}
	
	int sumRegion(int row1, int col1, int row2, int col2) {
		return prefix[row2 + 1][col2 + 1] 
			 - prefix[row2 + 1][col1] 
			 - prefix[row1][col2 + 1] 
			 + prefix[row1][col1];
	}
};