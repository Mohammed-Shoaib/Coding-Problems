/*
Problem Statement: https://leetcode.com/problems/number-of-segments-in-a-string/
Time: O(n)
Space: O(1)
Author: Mohammed Shoaib, github.com/Mohammed-Shoaib
*/

class Solution {
public:
	int countSegments(string s) {
		int cnt = 0;
		char prev = ' ';
		
		for (char& c: s) {
			if (prev == ' ' && c != ' ')
				cnt++;
			prev = c;
		}
		
		return cnt;
	}
};