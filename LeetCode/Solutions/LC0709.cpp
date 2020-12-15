/*
Problem Statement: https://leetcode.com/problems/to-lower-case/
Time: O(n)
Space: O(n)
Author: Mohammed Shoaib, github.com/Mohammed-Shoaib
*/

class Solution {
public:
	string toLowerCase(string str) {
		for (char& c: str)
			c += (c >= 'A' && c <= 'Z') ? 32 : 0;
		return str;
	}
};