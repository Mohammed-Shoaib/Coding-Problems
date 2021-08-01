/*
Problem Statement: https://leetcode.com/problems/isomorphic-strings/
Time: O(n)
Space: O(256)
Author: Mohammed Shoaib, github.com/Mohammed-Shoaib
*/

class Solution {
public:
	bool isIsomorphic(string s, string t) {
		int n = s.length();
		unordered_set<char> seen;
		unordered_map<char, char> mp;
		
		for (int i = 0; i < n; i++) {
			if (!seen.count(t[i]) && !mp.count(s[i])) {
				mp[s[i]] = t[i];
				seen.insert(t[i]);
			}
			else if (mp[s[i]] != t[i])
				return false;
		}
		
		return true;
	}
};