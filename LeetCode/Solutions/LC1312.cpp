/*
Problem Statement: https://leetcode.com/problems/minimum-insertion-steps-to-make-a-string-palindrome/
*/

class Solution {
public:
	int minInsertions(string& s) {
		int n = s.length();
		int dp[n][n] = {};

		// Dynamic Programming
		for (int i = n - 2; i >= 0; i--)
			for (int j = i + 1; j < n; j++) {
				if (s[i] == s[j])
					dp[i][j] = dp[i + 1][j - 1];
				else
					dp[i][j] = 1 + min(dp[i + 1][j], dp[i][j - 1]);
			}

		return dp[0][n - 1];
	}
};