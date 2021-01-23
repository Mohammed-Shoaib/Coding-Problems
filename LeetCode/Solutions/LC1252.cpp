/*
Problem Statement: https://leetcode.com/problems/cells-with-odd-values-in-a-matrix/
Time: O(n • m)
Space: O(n + m)
Author: Mohammed Shoaib, github.com/Mohammed-Shoaib
*/

class Solution {
public:
	int oddCells(int n, int m, vector<vector<int>>& indices) {
		int odd = 0;
		vector<bool> row(n), col(m);
		
		for (auto& v: indices) {
			row[v[0]] = row[v[0]] ^ 1;
			col[v[1]] = col[v[1]] ^ 1;
		}
		
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				odd += row[i] ^ col[j];
		
		return odd;
	}
};