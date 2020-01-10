/*
Problem Statement: https://leetcode.com/problems/valid-parentheses/
*/

class Solution {
public:
    bool isValid(string s) {
    	stack<char> st;
    	unordered_map<char, char> map;
    	map[')'] = '(';
    	map['}'] = '{';
    	map[']'] = '[';
    	
    	for (int i = 0; i < s.length(); i++) {
    		if (s[i] == '(' || s[i] == '{' || s[i] == '[')
    			st.push(s[i]);
    		else if (st.empty() || map[s[i]] != st.top())
    			return false;
    		else
    			st.pop();
    	}

    	return st.empty();
    }
};