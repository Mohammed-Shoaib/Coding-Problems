/*
Problem Statement: https://leetcode.com/problems/perform-string-shifts/
Time: O(n + m)
Space: O(1)
Author: Mohammed Shoaib, github.com/Mohammed-Shoaib
*/

class Solution {
public:
	string stringShift(string s, vector<vector<int>>& shift) {
		int r = 0, n = s.length(), m = shift.size();
		for (vector<int>& move: shift)
			r += move[0] ? move[1] : -move[1];
		r = (n - r % n) % n;
		rotate(s.begin(), s.begin() + r, s.end());
		return s;
	}
};