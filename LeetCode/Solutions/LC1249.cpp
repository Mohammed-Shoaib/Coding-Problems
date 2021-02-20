/*
Problem Statement: https://leetcode.com/problems/minimum-remove-to-make-valid-parentheses/
Time: O(n)
Space: O(n)
Author: Mohammed Shoaib, github.com/Mohammed-Shoaib
*/

class Solution {
public:
	string minRemoveToMakeValid(string s) {
		int bal, close, pos;
		bal = close = pos = 0;
		
		for (char& c: s)
			if (c == ')')
				close++;
		
		for (char& c: s) {
			if (c == ')')
				close--;
			if (c == '(' && bal == close || c == ')' && bal == 0)
				continue;
			else if (c == '(')
				bal++;
			else if (c == ')')
				bal--;
			s[pos++] = c;
		}
		s.resize(pos);
		
		return s;
	}
};