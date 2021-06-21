/*
Problem Statement: https://leetcode.com/problems/consecutive-characters/
Time: O(n)
Space: O(1)
Author: Mohammed Shoaib, github.com/Mohammed-Shoaib
*/

class Solution {
public:
	int maxPower(string s) {
		int max_cnt, cnt, n = s.length();
		max_cnt = cnt = 1;
		
		for (int i = 1; i < n; i++) {
			if (s[i - 1] == s[i])
				cnt++;
			else
				cnt = 1;
			max_cnt = max(cnt, max_cnt);
		}
		
		return max_cnt;
	}
};