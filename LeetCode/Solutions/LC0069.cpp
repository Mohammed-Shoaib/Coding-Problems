/*
Problem Statement: https://leetcode.com/problems/sqrtx/
*/

class Solution {
public:
    int mySqrt(int x) {
		int low, mid, high;
		low = 1;
		high = x;
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