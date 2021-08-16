/*
Problem Statement: https://leetcode.com/problems/delete-operation-for-two-strings/
Time: O(m • n)
Space: O(m • n)
Author: Mohammed Shoaib, github.com/Mohammed-Shoaib
*/

class Solution {
public:
	int minimumDeleteSum(string s1, string s2) {
		int m = s1.length(), n = s2.length();
		vector<vector<int>> dp(m + 1, vector<int>(n + 1));
		
		// initialization
		for (int i = 1; i <= m; i++)
			dp[i][0] = s1[i - 1] + dp[i - 1][0];
		for (int j = 1; j <= n; j++)
			dp[0][j] = s2[j - 1] + dp[0][j - 1];
		
		// dynamic programming
		for (int i = 1; i <= m; i++)
			for (int j = 1; j <= n; j++) {
				if (s1[i - 1] == s2[j - 1])
					dp[i][j] = dp[i - 1][j - 1];
				else
					dp[i][j] = min(s1[i - 1] + dp[i - 1][j], s2[j - 1] + dp[i][j - 1]);
			}
		
		return dp[m][n];
	}
};