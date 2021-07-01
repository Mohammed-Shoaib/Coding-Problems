/*
Problem Statement: https://leetcode.com/problems/replace-all-digits-with-characters/
Time: O(n)
Space: O(n)
Author: Mohammed Shoaib, github.com/Mohammed-Shoaib
*/

class Solution {
public:
	string replaceDigits(string s) {
		int n = s.length();
		for (int i = 1; i < n; i += 2)
			s[i] += s[i - 1] - '0';
		return s;
	}
};