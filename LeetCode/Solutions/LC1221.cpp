/*
Problem Statement: https://leetcode.com/problems/split-a-string-in-balanced-strings/
*/

class Solution {
public:
	int balancedStringSplit(string &s) {
		int bal, L_cnt, R_cnt;
		bal = L_cnt = R_cnt = 0;

		for (int i = 0; i < s.length(); i++) {
			(s[i] == 'L') ? L_cnt++ : R_cnt++;
			if (L_cnt == R_cnt)
				bal++;
		}
		
		return bal;
	}
};