/*
Problem Statement: https://leetcode.com/problems/palindrome-partitioning/
Time: O(n • 2ⁿ⁻¹)
Space: O(n • 2ⁿ⁻¹)
Author: Mohammed Shoaib, github.com/Mohammed-Shoaib
*/

class Solution {
public:
	vector<vector<string>> partition(string s) {
		int n = s.length();
		vector<vector<string>> dp[n + 1];
		
		// initialization
		dp[0] = { {} };
		
		// dynamic programming
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= i; j++) {
				if (!is_palindrome(i - j, i - 1, s))
					continue;
				for (vector<string>& x: dp[i - j]) {
					dp[i].push_back(x);
					dp[i].back().push_back(s.substr(i - j, j));
				}
			}
		
		return dp[n];
	}
	
	bool is_palindrome(int l, int r, string& s) {
		while (l < r)
			if (s[l++] != s[r--])
				return false;
		return true;
	}
};