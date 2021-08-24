/*
Problem Statement: https://leetcode.com/problems/find-and-replace-in-string/
Time: O(n + m • max_len)
Space: O(n + m • max_len)
Author: Mohammed Shoaib, github.com/Mohammed-Shoaib
*/

class Solution {
public:
	string findReplaceString(string& s, vector<int>& indexes, vector<string>& sources, vector<string>& targets) {
		int m = indexes.size(), n = s.length();
		string t;
		vector<pair<int, string>> mp(n);
		
		for (int i = 0; i < m; i++) {
			int len = sources[i].length();
			if (!s.compare(indexes[i], len, sources[i]))
				mp[indexes[i]] = {len, targets[i]};
		}
		
		for (int i = 0; i < n; i++) {
			if (!mp[i].first)
				t += s[i];
			else {
				t += mp[i].second;
				i += mp[i].first - 1;
			}
		}
		
		return t;
	}
};