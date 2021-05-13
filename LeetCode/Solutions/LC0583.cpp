/*
Problem Statement: https://leetcode.com/problems/delete-operation-for-two-strings/
Time: O(m • n)
Space: O(m • n)
Author: Mohammed Shoaib, github.com/Mohammed-Shoaib
*/

class Solution {
public:
	int minDistance(string word1, string word2) {
		int m = word1.length(), n = word2.length();
		vector<vector<int>> dp(m + 1, vector<int>(n + 1));
		
		// initialization
		iota(dp[0].begin(), dp[0].end(), 0);
		for (int i = 1; i <= m; i++)
			dp[i][0] = i;
		
		// dynamic programming
		for (int i = 1; i <= m; i++)
			for (int j = 1; j <= n; j++) {
				if (word1[i - 1] == word2[j - 1])
					dp[i][j] = dp[i - 1][j - 1];
				else
					dp[i][j] = 1 + min(dp[i - 1][j], dp[i][j - 1]);
			}
		
		return dp[m][n];
	}
};