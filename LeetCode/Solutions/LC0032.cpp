/*
Problem Statement: https://leetcode.com/problems/longest-valid-parentheses/
Time: O(n)
Space: O(1)
Author: Mohammed Shoaib, github.com/Mohammed-Shoaib
*/

class Solution {
public:
	int longestValidParentheses(string s) {
		int max_len, len, bal, n = s.length();
		max_len = len = bal = 0;
		
		for (int i = 0; i < n; i++) {
			len++;
			bal += 2 * (s[i] == '(') - 1;
			
			if (bal < 0)
				len = bal = 0;
			else if (bal == 0)
				max_len = max(len, max_len);
		}
		bal = len = 0;
		
		for (int i = n - 1; i >= 0; i--) {
			len++;
			bal += 2 * (s[i] == ')') - 1;
			
			if (bal < 0)
				len = bal = 0;
			else if (bal == 0)
				max_len = max(len, max_len);
		}
		
		return max_len;
	}
};