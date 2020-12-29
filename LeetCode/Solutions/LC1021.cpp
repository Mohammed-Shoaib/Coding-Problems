/*
Problem Statement: https://leetcode.com/problems/remove-outermost-parentheses/
Time: O(n)
Space: O(n)
Author: Mohammed Shoaib, github.com/Mohammed-Shoaib
*/

class Solution {
public:
	string removeOuterParentheses(string S) {
		string T;
		int bal = 0;
		
		for (char& c: S) {
			bal += 2 * (c == '(') - 1;
			if (bal + c != ')')
				T += c;
		}
		
		return T;
	}
};