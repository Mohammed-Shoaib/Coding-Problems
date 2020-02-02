/*
Problem Statement: https://leetcode.com/problems/word-break/
*/

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
		int max_len, n;
		max_len = 0;
		n = s.length();
		vector<bool> dp(n + 1);
		unordered_set<string> m(wordDict.begin(), wordDict.end());

		// Initialize
		dp[0] = true;
		for (auto& word: wordDict)
			max_len = max((int)word.length(), max_len);
		
		// Dynamic Programming
		for (int i = 1; i <= n; i++)
			for (int j = i - 1; j >= max(0, i - max_len); j--)
				if (dp[j]) {
					string t = s.substr(j, i - j);
					if (m.count(t)) {
						dp[i] = true;
						break;
					}
				}

		return dp[n];
    }
};