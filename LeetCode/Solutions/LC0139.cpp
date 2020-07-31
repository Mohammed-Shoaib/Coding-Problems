/*
Problem Statement: https://leetcode.com/problems/word-break/
Time: O(n² • max_len)
Space: O(n + words)
Author: Mohammed Shoaib, github.com/Mohammed-Shoaib
*/

class Solution {
public:
	bool wordBreak(string s, vector<string>& wordDict) {
		int max_len = 0, n = s.length();
		vector<bool> dp(n + 1);
		unordered_set<string> words(wordDict.begin(), wordDict.end());

		// initialization
		dp[0] = true;
		for (string& word: wordDict)
			max_len = max(static_cast<int>(word.length()), max_len);
		
		// dynamic programming
		for (int i = 1; i <= n; i++)
			for (int j = i - 1; j >= max(0, i - max_len); j--)
				if (dp[j] && words.count(s.substr(j, i - j)))
					dp[i] = true;

		return dp[n];
	}
};