/*
Problem Statement: https://leetcode.com/problems/backspace-string-compare/
Time: O(m + n)
Space: O(m + n)
Author: Mohammed Shoaib, github.com/Mohammed-Shoaib
*/

class Solution {
public:
	bool backspaceCompare(string S, string T) {
		int m = assign(S), n = assign(T);
		if (m != n)
			return false;
		for (int i = 0; i < m; i++)
			if (S[i] != T[i])
				return false;
		return true;
	}
	
	int assign(string& s) {
		int i = 0;
		for (char& c: s) {
			if (c == '#')
				i = max(0, i - 1);
			else
				s[i++] = c;
		}
		return i;
	}
};