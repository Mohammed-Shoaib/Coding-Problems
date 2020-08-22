/*
Problem Statement: https://leetcode.com/problems/word-break-ii/
Time: O(2ⁿ • max_len)
Space: O(2ⁿ + words)
Author: Mohammed Shoaib, github.com/Mohammed-Shoaib
*/

class Solution {
public:
	vector<string> wordBreak(string s, vector<string>& wordDict) {
		int max_len, n = s.length();
		vector<bool> dp(n + 1);
		vector<string> sentences;
		vector<vector<int>> adj(n);
		unordered_set<string> words(wordDict.begin(), wordDict.end());
		
		// initialization
		dp[0] = true;
		max_len = 0;
		for (string& word: wordDict)
			max_len = max(static_cast<int>(word.length()), max_len);
		
		// dynamic programming
		for (int i = 1; i <= n; i++)
			for (int j = i - 1; j >= max(0, i - max_len); j--)
				if (dp[j] && words.count(s.substr(j, i - j))) {
					dp[i] = true;
					adj[j].push_back(i);
				}
		
		// use backtracking to construct all possible sentences
		if (dp[n])
			dfs(0, s, "", sentences, adj);
		
		return sentences;
	}
	
	void dfs(int u, string& s, string sentence, vector<string>& sentences, vector<vector<int>>& adj) {
		if (u == adj.size()) {
			sentences.push_back(sentence);
			return;
		}
		if (!sentence.empty())
			sentence += " ";
		for (int v: adj[u])
			dfs(v, s, sentence + s.substr(u, v - u), sentences, adj);
	}
};