/*
Problem Statement: https://leetcode.com/problems/longest-string-chain/
Time: O(n • log n + n • max_len)
Space: O(n • max_len)
Author: Mohammed Shoaib, github.com/Mohammed-Shoaib
*/

class Solution {
public:
	int longestStrChain(vector<string> words) {
		int max_len = 0, n = words.size();
		unordered_map<string, int> dp;
		
		// sort by lengths
		sort(words.begin(), words.end(), [](string& l, string& r) {
			return l.length() < r.length();
		});
		
		// dynamic programming
		for (int i = 0; i < n; i++) {
			int len = 1;
			for (int j = 0; j < words[i].length(); j++) {
				string sub = words[i].substr(0, j) + words[i].substr(j + 1);
				auto it = dp.find(sub);
				if (it != dp.end())
					len = max(1 + it->second, len);
			}
			dp[words[i]] = len;
			max_len = max(len, max_len);
		}
		
		return max_len;
	}
};