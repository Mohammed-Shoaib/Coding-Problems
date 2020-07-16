/*
Problem Statement: https://leetcode.com/problems/angle-between-hands-of-a-clock/
Time: O(1)
Space: O(1)
Author: Mohammed Shoaib, github.com/Mohammed-Shoaib
*/

class Solution {
public:
	double angleClock(int hour, int minutes) {
		double am, ah, angle;
		am = 6 * minutes;
		ah = 30 * (hour % 12) + 0.5 * minutes;
		angle = abs(am - ah);
		return min(angle, 360 - angle);
	}
};