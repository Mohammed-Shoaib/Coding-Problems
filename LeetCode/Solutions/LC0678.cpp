/*
Problem Statement: https://leetcode.com/problems/valid-parenthesis-string/
*/

class Solution {
public:
	bool checkValidString(string s) {
		int cmin, cmax;
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