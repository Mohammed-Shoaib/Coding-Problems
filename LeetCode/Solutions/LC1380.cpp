/*
Problem Statement: https://leetcode.com/problems/lucky-numbers-in-a-matrix/
*/

class Solution {
public:
	vector<int> luckyNumbers (vector<vector<int>>& matrix) {
		int m, n, mn, pos;
		m = matrix.size();
		n = matrix[0].size();
		vector<int> lucky;

		for (int i = 0; i < m; i++) {
			pos = distance(matrix[i].begin(), min_element(matrix[i].begin(), matrix[i].end()));
			mn = matrix[i][pos];
			for (int j = 0; j < m; j++)
				mn = max(matrix[j][pos], mn);
			if (mn == matrix[i][pos])
				lucky.push_back(mn);
		}
		
		return lucky;
	}
};