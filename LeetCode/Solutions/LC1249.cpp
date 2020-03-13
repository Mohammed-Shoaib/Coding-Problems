/*
Problem Statement: https://leetcode.com/problems/minimum-remove-to-make-valid-parentheses/
*/

class Solution {
public:
    string minRemoveToMakeValid(string& s) {
		int n = s.length();
		string valid = "";
		stack<int> st;
		vector<bool> mark(n);

		for (int i = 0; i < n; i++) {
			if (s[i] == '(')
				st.push(i);
			else if (s[i] == ')') {
				if (st.empty())
					mark[i] = true;
				else
					st.pop();
			}
		}
		
		while (!st.empty()) {
			mark[st.top()] = true;
			st.pop();
		}

		for (int i = 0; i < n; i++)
			if (!mark[i])
				valid += s[i];
		
		return valid;
    }
};