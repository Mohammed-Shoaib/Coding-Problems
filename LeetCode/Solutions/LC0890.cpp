/*
Problem Statement: https://leetcode.com/problems/find-and-replace-pattern/
Time: O(m • n)
Space: O(m • n)
Author: Mohammed Shoaib, github.com/Mohammed-Shoaib
*/

class Solution {
public:
	vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
		int m = words.size();
		vector<string> matches;
		
		for (string& word: words)
			if (match(word, pattern))
				matches.push_back(word);
		
		return matches;
	}
	
	bool match(string& word, string& pattern) {
		int n = pattern.size();
		unordered_set<char> seen;
		unordered_map<char, char> mp;
		
		for (int i = 0; i < n; i++) {
			if (!mp.count(pattern[i])) {
				if (!seen.insert(word[i]).second)
					return false;
				mp[pattern[i]] = word[i];
			}
			if (mp[pattern[i]] != word[i])
				return false;
		}
		
		return true;
	}
};