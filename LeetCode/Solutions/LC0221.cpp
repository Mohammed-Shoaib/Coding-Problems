/*
Problem Statement: https://leetcode.com/problems/maximal-square/
*/

class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
		if (matrix.empty())	
			return 0;
        int max_len, m, n;
		max_len = 0;
		m = matrix.size();
		n = matrix[0].size();
		int dp[m + 1][n + 1] = {};
		
		// dynamic programming
		for (int i = 1; i <= m; i++)
			for (int j = 1; j <= n; j++)
				if (matrix[i - 1][j - 1] == '1') {
					dp[i][j] = 1 + min({dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]});
					max_len = max(dp[i][j], max_len);
				}
		
		return max_len * max_len;
    }
};