/*
Problem Statement: https://leetcode.com/problems/break-a-palindrome/
*/

class Solution {
public:
	string breakPalindrome(string& s) {
		int n = s.length();
		for (int i = 0; i < n / 2; i++)
			if (s[i] != 'a') {
				s[i] = 'a';
				return s;
			}
		s[n - 1] = 'b';
		return (n == 1) ? "" : s;
	}
};