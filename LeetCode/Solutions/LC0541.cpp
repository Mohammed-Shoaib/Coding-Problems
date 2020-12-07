/*
Problem Statement: https://leetcode.com/problems/reverse-string-ii/
*/

class Solution {
public:
	string reverseStr(string s, int k) {
		for (int j, i = 0; i < s.length(); i += 2 * k) {
			j = min(i + k, (int) s.length());
			reverse(s.begin() + i, s.begin() + j);
		}
		return s;
	}
};