/*
Problem Statement: https://leetcode.com/problems/find-the-difference/
Time: O(n)
Space: O(1)
Author: Mohammed Shoaib, github.com/Mohammed-Shoaib
*/

class Solution {
public:
	char findTheDifference(string s, string t) {
		char extra = 0;
		for (char& c: s)
			extra ^= c;
		for (char& c: t)
			extra ^= c;
		return extra;
	}
};