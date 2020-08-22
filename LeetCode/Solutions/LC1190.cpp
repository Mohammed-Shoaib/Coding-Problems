/*
Problem Statement: https://leetcode.com/problems/reverse-substrings-between-each-pair-of-parentheses/
Time: O(n²)
Space: O(n)
Author: Mohammed Shoaib, github.com/Mohammed-Shoaib
*/

class Solution {
public:
	string reverseParentheses(string s) {
		int n = s.length();
		string rev;
		stack<int> st;
		
		for (int i = 0; i < n; i++) {
			if (s[i] == '(')
				st.push(i);
			else if (s[i] == ')') {
				int start = st.top();
				st.pop();
				reverse(s.begin() + start, s.begin() + i);
			}
		}
		
		for (int i = 0; i < n; i++)
			if (s[i] != '(' && s[i] != ')')
				rev += s[i];
		
		return rev;
	}
};