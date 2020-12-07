/*
Problem Statement: https://leetcode.com/problems/reverse-words-in-a-string-iii/
*/

class Solution {
public:
	string reverseWords(string s) {
		int n = s.length();
		for (int i = 0, j = 0; j < n; i = ++j) {
			while (j < n && s[j] != ' ')
				j++;
			reverse(s.begin() + i, s.begin() + j);
		}
		return s;
	}
};