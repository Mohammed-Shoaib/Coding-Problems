/*
Problem Statement: https://leetcode.com/problems/valid-palindrome-ii/
Time: O(n)
Space: O(1)
Author: Mohammed Shoaib, github.com/Mohammed-Shoaib
*/

class Solution {
public:
	bool validPalindrome(string s) {
		int n = s.length();
		
		for (int l = 0, r = n - 1; l < r; l++, r--)
			if (s[l] != s[r])
				return is_palindrome(l + 1, r, s) || is_palindrome(l, r - 1, s);
		
		return true;
	}

	bool is_palindrome(int l, int r, string& s) {
		while (l < r) {
			if (s[l++] != s[r--])
				return false;
		}
		return true;
	}
};