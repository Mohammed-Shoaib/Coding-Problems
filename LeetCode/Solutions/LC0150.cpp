/*
Problem Statement: https://leetcode.com/problems/evaluate-reverse-polish-notation/
Time: O(n)
Space: O(n)
Author: Mohammed Shoaib, github.com/Mohammed-Shoaib
*/

class Solution {
public:
	int evalRPN(vector<string>& tokens) {
		stack<int> st;
		for (string& token: tokens) {
			if (isdigit(token.back())) {
				st.push(stoi(token));
				continue;
			}
			int a, b;
			b = st.top();
			st.pop();
			a = st.top();
			st.pop();
			if (token == "+")
				st.push(a + b);
			else if (token == "-")
				st.push(a - b);
			else if (token == "*")
				st.push(a * b);
			else
				st.push(a / b);
		}
		return st.top();
	}
};