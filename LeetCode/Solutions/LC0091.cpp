/*
Problem Statement: https://leetcode.com/problems/decode-ways/
Time: O(n)
Space: O(n)
Author: Mohammed Shoaib, github.com/Mohammed-Shoaib
*/

class Solution {
public:
	int numDecodings(string s) {
		int n = s.length();
		vector<int> dp(n + 1);
		
		// base case
		dp[0] = 1;
		dp[1] = (!s.empty() && s[0] != '0');
		
		// dynamic programming
		for (int i = 2; i <= n; i++) {
			if (s[i - 1] != '0')
				dp[i] += dp[i - 1];
			if (s[i - 2] == '1' || s[i - 2] == '2' && s[i - 1] <= '6')
				dp[i] += dp[i - 2];
		}
		
		return dp[n];
	}
};