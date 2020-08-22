/*
Problem Statement: https://leetcode.com/problems/is-subsequence/
Time: O(min(s, t))
Space: O(1)
Author: Mohammed Shoaib, github.com/Mohammed-Shoaib
*/

class Solution {
public:
	bool isSubsequence(string s, string t) {
		if (s.empty())
			return true;
		
		int i = 0;
		for (char& c: t) {
			i += (s[i] == c);
			if (i == s.length())
				return true;
		}
		
		return false;
	}
};