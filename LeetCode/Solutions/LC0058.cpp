/*
Problem Statement: https://leetcode.com/problems/length-of-last-word/
Time: O(n)
Space: O(1)
Author: Mohammed Shoaib, github.com/Mohammed-Shoaib
*/

class Solution {
public:
	int lengthOfLastWord(string s) {
		int len = 0, n = s.length();
		for (int i = n - 1; i >= 0; i--) {
			if (s[i] != ' ')
				len++;
			else if (len)
				return len;
		}
		return len;
	}
};