/*
Problem Statement: https://leetcode.com/problems/generate-parentheses/
Time: O(n • 2ⁿ)
Space: O(n • 2ⁿ)
Author: Mohammed Shoaib, github.com/Mohammed-Shoaib
*/

class Solution {
public:
	vector<string> generateParenthesis(int n) {
		vector<string> combs;
		
		function<void(int, int, string)> backtrack = [&](int open, int close, string comb) {
			if (comb.length() == 2 * n) {
				combs.push_back(comb);
				return;
			}
			if (open < n)
				backtrack(open + 1, close, comb + '(');
			if (close < open)
				backtrack(open, close + 1, comb + ')');
		};
		backtrack(0, 0, "");
		
		return combs;
	}
};