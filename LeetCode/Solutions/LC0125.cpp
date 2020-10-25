/*
Problem Statement: https://leetcode.com/problems/valid-palindrome/
Time: O(n)
Space: O(1)
Author: Mohammed Shoaib, github.com/Mohammed-Shoaib
*/

class Solution {
public:
	bool isPalindrome(string s) {
		int l = 0, r = (int) s.length() - 1;

		while (l < r) {
			if (!isalnum(s[l]))
				l++;
			else if (!isalnum(s[r]))
				r--;
			else if (tolower(s[l++]) != tolower(s[r--]))
				return false;
		}

		return true;
	}
};