/*
Problem Statement: https://leetcode.com/problems/check-if-it-is-a-straight-line/
*/

class Solution {
public:
	bool checkStraightLine(vector<vector<int>>& coordinates) {
		int x, y, dx, dy;
		x = coordinates[0][0];
		y = coordinates[0][1];
		dx = coordinates[1][0] - x;
		dy = coordinates[1][1] - y;

		// based on slope of points
		// (y2 - y1) / (x2 - x1) == (y3 - y1) / (x3 - x1)
		// (y2 - y1) * (x3 - x1) == (x2 - x1) * (y3 - y1)
		for (vector<int>& p: coordinates)
			if (dy * (p[0] - x) != dx * (p[1] - y))
				return false;
		
		return true;
	}
};