/*
Problem Statement: https://leetcode.com/problems/generate-a-string-with-characters-that-have-odd-counts/
*/

class Solution {
public:
	string generateTheString(int n) {
		string s(n - 1, 'a');
		s += (n & 1) ? 'a' : 'b';
		return s;
	}
};