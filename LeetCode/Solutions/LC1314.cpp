/*
Problem Statement: https://leetcode.com/problems/matrix-block-sum/
Time: O(m • n)
Space: O(m • n)
Author: Mohammed Shoaib, github.com/Mohammed-Shoaib
*/

class Solution {
public:
	vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int K) {
		int m, n, lr, lc, hr, hc;
		m = mat.size();
		n = mat[0].size();
		vector<vector<int>> res(m, vector<int>(n)), prefix(m + 1, vector<int>(n + 1));
		
		// construct prefix sum array
		for (int i = 0; i < m; i++)
			for (int j = 0; j < n; j++)
				prefix[i + 1][j + 1] = mat[i][j] + prefix[i][j + 1] + prefix[i + 1][j] - prefix[i][j];
		
		// compute sum for all elements using prefix array
		for (int i = 0; i < m; i++)
			for (int j = 0; j < n; j++) {
				lr = max(0, i - K);
				lc = max(0, j - K);
				hr = min(m, i + K + 1);
				hc = min(n, j + K + 1);
				res[i][j] = prefix[hr][hc] - prefix[lr][hc] - prefix[hr][lc] + prefix[lr][lc];
			}
		
		return res;
	}
};