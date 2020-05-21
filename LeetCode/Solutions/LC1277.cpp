/*
Problem Statement: https://leetcode.com/problems/count-square-submatrices-with-all-ones/
*/

class Solution {
public:
	int countSquares(vector<vector<int>>& matrix) {
		int squares, m, n;
		squares = 0;
		m = matrix.size();
		n = matrix[0].size();
		vector<vector<int>> dp(m + 1, vector<int>(n + 1));
		
		// dynamic programming
		for (int i = 1; i <= m; i++)
			for (int j = 1; j <= n; j++) 
				if (matrix[i - 1][j - 1]) {
					dp[i][j] = 1 + min({dp[i][j - 1], dp[i - 1][j], dp[i - 1][j - 1]});
					squares += dp[i][j];
				}
		
		return squares;
	}
};