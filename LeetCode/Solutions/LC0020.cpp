/*
Problem Statement: https://leetcode.com/problems/valid-parentheses/
Time: O(n)
Space: O(n)
Author: Mohammed Shoaib, github.com/Mohammed-Shoaib
*/

class Solution {
public:
	bool isValid(string s) {
		stack<char> st;
		unordered_map<char, char> mp = {
			{')', '('},
			{'}', '{'},
			{']', '['}
		};
		
		for (int i = 0; i < s.length(); i++) {
			if (!mp.count(s[i]))
				st.push(s[i]);
			else if (st.empty() || mp[s[i]] != st.top())
				return false;
			else
				st.pop();
		}
		
		return st.empty();
	}
};