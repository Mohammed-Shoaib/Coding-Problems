/*
Problem Statement: https://leetcode.com/problems/reverse-string/
Time: O(n)
Space: O(1)
Author: Mohammed Shoaib, github.com/Mohammed-Shoaib
*/

class Solution {
public:
	void reverseString(vector<char>& s) {
		int n = s.size();
		for (int i = 0; i < n / 2; i++)
			swap(s[i], s[n - i - 1]);
	}
};