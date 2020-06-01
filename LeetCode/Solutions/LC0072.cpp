/*
Problem Statement: https://leetcode.com/problems/edit-distance/
*/

class Solution {
public:
	int minDistance(string word1, string word2) {
		int m, n;
		m = word1.length();
		n = word2.length();
		int dp[m + 1][n + 1];
		
		// base cases
		dp[0][0] = 0;
		for (int i = 1; i <= m; i++)
			dp[i][0] = i;
		for (int j = 1; j <= n; j++)
			dp[0][j] = j;

		// dynamic programming
		for (int i = 1; i <= m; i++)
			for (int j = 1; j <= n; j++)
				dp[i][j] = min({dp[i][j - 1] + 1,
								dp[i - 1][j] + 1,
								dp[i - 1][j - 1] + (word1[i - 1] != word2[j - 1])});

		return dp[m][n];
	}
};