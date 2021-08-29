/*
Problem Statement: https://leetcode.com/problems/broken-calculator/
Time: O(log Y)
Space: O(1)
Author: Mohammed Shoaib, github.com/Mohammed-Shoaib
*/

class Solution {
public:
	int brokenCalc(int X, int Y) {
		int steps = 0;
		while (Y > X) {
			steps++;
			if (Y & 1)
				Y++;
			else
				Y /= 2;
		}
		return steps + X - Y;
	}
};