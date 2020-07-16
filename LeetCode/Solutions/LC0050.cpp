/*
Problem Statement: https://leetcode.com/problems/powx-n/
Time: O(log n)
Space: O(1)
Author: Mohammed Shoaib, github.com/Mohammed-Shoaib
*/

class Solution {
public:
	double myPow(double x, int n) {
		double y = 1;
		if (x == 0)
			return 0;
		while (n) {
			if (n & 1)
				y = (n < 0) ? y / x : y * x;
			x *= x;
			n /= 2;
		}
		return y;
	}
};