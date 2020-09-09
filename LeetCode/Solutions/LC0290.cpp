/*
Problem Statement: https://leetcode.com/problems/word-pattern/
Time: O(m + n)
Space: O(m + n)
Author: Mohammed Shoaib, github.com/Mohammed-Shoaib
*/

class Solution {
public:
	bool wordPattern(string pattern, string str) {
		int i, m = pattern.length();
		string token;
		istringstream ss(str);
		unordered_map<char, int> pat_mp;
		unordered_map<string, int> str_mp;
		
		for (i = 0; ss >> token; i++) {
			if (i == m || pat_mp[pattern[i]] != str_mp[token])
				return false;
			pat_mp[pattern[i]] = str_mp[token] = i + 1;
		}
		
		return i == m;
	}
};