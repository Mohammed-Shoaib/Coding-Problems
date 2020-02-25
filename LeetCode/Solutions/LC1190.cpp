/*
Problem Statement: https://leetcode.com/problems/reverse-substrings-between-each-pair-of-parentheses/
*/

class Solution {
public:
    string reverseParentheses(string s) {
    	string rev;
    	stack<int> st;

    	for (int i = 0; i < s.length(); i++) {
    		if (s[i] == '(')
    			st.push(i);
    		else if (s[i] == ')') {
    			int start = st.top();
    			st.pop();
    			reverse(s.begin() + start, s.begin() + i);
    		}
    	}

    	for (int i = 0; i < s.length(); i++)
    		if (s[i] != '(' && s[i] != ')')
    			rev += s[i];

    	return rev;
    }
};