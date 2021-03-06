/*
Problem Statement: https://leetcode.com/problems/replace-all-s-to-avoid-consecutive-repeating-characters/
Time: O(n)
Space: O(1)
Author: Mohammed Shoaib, github.com/Mohammed-Shoaib
*/

class Solution {
public:
	string modifyString(string s) {
		int n = s.length();
		for (int i = 0; i < n; i++) {
			if (s[i] != '?')
				continue;
			char c = 'a';
			while (c == s[max(0, i - 1)] || c == s[min(n - 1, i + 1)])
				c++;
			s[i] = c;
		}
		return s;
	}
};