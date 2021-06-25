/*
Problem Statement: https://leetcode.com/problems/merge-strings-alternately/
Time: O(m + n)
Space: O(m + n)
Author: Mohammed Shoaib, github.com/Mohammed-Shoaib
*/

class Solution {
public:
	string mergeAlternately(string word1, string word2) {
		int m = word1.length(), n = word2.length();
		string s;
		
		for (int i = 0; i < m || i < n; i++) {
			if (i < m)
				s += word1[i];
			if (i < n)
				s += word2[i];
		}
		
		return s;
	}
};