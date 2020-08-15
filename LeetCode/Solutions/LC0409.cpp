/*
Problem Statement: https://leetcode.com/problems/longest-palindrome/
Time: O(n)
Space: O(1)
Author: Mohammed Shoaib, github.com/Mohammed-Shoaib
*/

class Solution {
public:
	int longestPalindrome(string s) {
		vector<bool> seen(128);
		for (char& c: s)
			seen[c] = !seen[c];
		int odds = count(seen.begin(), seen.end(), true);
		return s.length() - max(0, odds - 1);
	}
};