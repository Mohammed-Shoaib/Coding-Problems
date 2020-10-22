/*
Problem Statement: https://leetcode.com/problems/minimum-add-to-make-parentheses-valid/
Time: O(n)
Space: O(1)
Author: Mohammed Shoaib, github.com/Mohammed-Shoaib
*/

class Solution {
public:
	int minAddToMakeValid(string S) {
		int cnt = 0, bal = 0;
		
		for (char& c: S) {
			if (c == '(')
				bal++;
			else if (bal > 0)
				bal--;
			else
				cnt++;
		}
		
		return cnt + bal;
	}
};