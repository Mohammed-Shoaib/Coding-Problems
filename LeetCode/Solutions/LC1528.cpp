/*
Problem Statement: https://leetcode.com/problems/shuffle-string/
Time: O(n)
Space: O(n)
Author: Mohammed Shoaib, github.com/Mohammed-Shoaib
*/

class Solution {
public:
	string restoreString(string s, vector<int>& indices) {
		int n = s.length();
		string t(s);
		for (int i = 0; i < n; i++)
			t[indices[i]] = s[i];
		return t;
	}
};