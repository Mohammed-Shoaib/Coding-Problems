/*
Problem Statement: https://leetcode.com/problems/repeated-substring-pattern/
Time: O(n)
Space: O(n)
Author: Mohammed Shoaib, github.com/Mohammed-Shoaib
*/

class Solution {
public:
	bool repeatedSubstringPattern(string s) {
		int n = s.length();
		return (s + s).substr(1, 2 * n - 2).find(s) != string::npos;
	}
};