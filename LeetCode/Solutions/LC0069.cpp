/*
Problem Statement: https://leetcode.com/problems/sqrtx/
Time: O(log x)
Space: O(1)
Author: Mohammed Shoaib, github.com/Mohammed-Shoaib
*/

class Solution {
public:
	int mySqrt(int x) {
		int mid, low = 1, high = x;
		
		// binary search
		while (low <= high) {
			mid = low + (high - low) / 2;
			if (mid > x / mid)
				high = mid - 1;
			else
				low = mid + 1;
		}
		
		return high;
	}
};