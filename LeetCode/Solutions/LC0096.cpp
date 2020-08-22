/*
Problem Statement: https://leetcode.com/problems/unique-binary-search-trees/
Time: O(n²)
Space: O(n)
Author: Mohammed Shoaib, github.com/Mohammed-Shoaib
*/

class Solution {
public:
	int numTrees(int n) {
		vector<int> dp(n + 1);
		
		// dynamic programming
		dp[0] = 1;
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= i; j++)
				dp[i] += dp[j - 1] * dp[i - j];
		
		return dp[n];
	}
};