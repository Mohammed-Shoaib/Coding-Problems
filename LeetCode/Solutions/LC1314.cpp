/*
Problem Statement: https://leetcode.com/problems/matrix-block-sum/
*/

class Solution {
public:
    vector< vector<int> > matrixBlockSum(vector< vector<int> >& mat, int K) {
		int m, n, lr, lc, hr, hc;
		m = mat.size();
		n = mat[0].size();
		int prefix[m + 1][n + 1] = {};
		vector< vector<int> > ans(m, vector<int>(n));

		// Construct prefix sum array
		for (int i = 0; i < m; i++)
			for (int j = 0; j < n; j++)
				prefix[i + 1][j + 1] = mat[i][j] + prefix[i][j + 1] + prefix[i + 1][j] - prefix[i][j];
		
		// Compute sum for all elements using prefix array
		for (int i = 0; i < m; i++)
			for (int j = 0; j < n; j++) {
				lr = max(0, i - K);
				lc = max(0, j - K);
				hr = min(m, i + K + 1);
				hc = min(n, j + K + 1);
				ans[i][j] = prefix[hr][hc] - prefix[lr][hc] - prefix[hr][lc] + prefix[lr][lc];
			}
		
		return ans;
    }
};