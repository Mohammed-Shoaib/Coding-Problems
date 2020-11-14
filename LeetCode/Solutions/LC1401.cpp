/*
Problem Statement: https://leetcode.com/problems/circle-and-rectangle-overlapping/
*/

class Solution {
public:
	bool checkOverlap(int radius, int x_center, int y_center, int x1, int y1, int x2, int y2) {
		int dx, dy;
		dx = x_center - clamp(x_center, x1, x2);
		dy = y_center - clamp(y_center, y1, y2);
		return dx * dx + dy * dy <= radius * radius;
	}
};