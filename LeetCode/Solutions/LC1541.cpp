/*
Problem Statement: https://leetcode.com/problems/minimum-insertions-to-balance-a-parentheses-string/
Time: O(n)
Space: O(1)
Author: Mohammed Shoaib, github.com/Mohammed-Shoaib
*/

class Solution {
public:
	int minInsertions(string s) {
		int cnt = 0, bal = 0;

		for (char& c: s) {
			if (c == '(') {
				if (bal & 1) {
					cnt++;
					bal--;
				}
				bal += 2;
			} else if (--bal < 0) {
				cnt++;
				bal += 2;
			}
		}

		return cnt + bal;
	}
};