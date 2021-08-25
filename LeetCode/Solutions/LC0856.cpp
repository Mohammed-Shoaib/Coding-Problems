/*
Problem Statement: https://leetcode.com/problems/score-of-parentheses/
Time: O(n)
Space: O(1)
Author: Mohammed Shoaib, github.com/Mohammed-Shoaib
*/

class Solution {
public:
	int scoreOfParentheses(string S) {
		int score, bal, n;
		score = bal = 0;
		n = S.length();
		
		for (int i = 0; i < n; i++) {
			bal += 2 * (S[i] == '(') - 1;
			if (S[i] == ')' && S[i - 1] == '(')
				score += 1 << bal;
		}
		
		return score;
	}
};