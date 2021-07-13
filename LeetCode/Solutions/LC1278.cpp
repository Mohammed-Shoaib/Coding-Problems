/*
Problem Statement: https://leetcode.com/problems/palindrome-partitioning-iii/
*/

class Solution {
public:
	int palindromePartition(string& s, int k) {
		int n = s.length();
		int dp[n][k], cost[n][n] = {0};
		fill_n(*dp, n * k, numeric_limits<int>::max());
		
		// Initialize cost matrix
		for (int l = 1; l < n; l++)
			for (int i = 0; i < n - l; i++)
				cost[i][i + l] = cost[i + 1][i + l - 1] + (s[i] != s[i + l]);
		
		// Base Case
		for (int i = 0; i < n; i++)
			dp[i][0] = cost[i][n - 1];
		
		// Dynamic Programming
		for (int l = 1; l < k; l++)
			for (int i = 0; i < n - l; i++)
				for (int j = i; j < n - l; j++)
					dp[i][l] = min(cost[i][j] + dp[j + 1][l - 1], dp[i][l]);
		
		return dp[0][k - 1];
	}
};