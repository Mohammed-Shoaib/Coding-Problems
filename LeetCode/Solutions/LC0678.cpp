/*
Problem Statement: https://leetcode.com/problems/valid-parenthesis-string/
Time: O(n)
Space: O(1)
Author: Mohammed Shoaib, github.com/Mohammed-Shoaib
*/

class Solution {
public:
	bool checkValidString(string s) {
		int n, cmin, cmax;
		n = s.length();
		cmin = cmax = 0;
		
		for (char& c: s) {
			if (c == '(') {
				cmin++;
				cmax++;
			} else if (c == ')') {
				cmin--;
				cmax--;
			} else {
				cmin--;		// change '*' to ')'
				cmax++;		// change '*' to '('
			}
			if (cmax < 0)
				return false;
			cmin = max(0, cmin);	// change '*' to empty
		}
		
		return cmin == 0;
	}
};