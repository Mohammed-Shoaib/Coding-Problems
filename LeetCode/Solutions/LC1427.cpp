/*
Problem Statement: https://leetcode.com/problems/perform-string-shifts/
*/

class Solution {
public:
	string stringShift(string s, vector<vector<int>>& shift) {
		int r = 0, n = s.length();
		for (vector<int>& move: shift)
			r += (move[0]) ? move[1] : -move[1];
		r = (n - r % n) % n;
		rotate(s.begin(), s.begin() + r, s.end());
		return s;
	}
};