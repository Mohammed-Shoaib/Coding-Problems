/*
Problem Statement: https://leetcode.com/problems/first-bad-version/
Time: O(API • log n)
Space: O(1)
Author: Mohammed Shoaib, github.com/Mohammed-Shoaib
*/

class Solution {
public:
	int firstBadVersion(int n) {
		int mid, low = 1, high = n;
		
		// binary search
		while (low < high) {
			mid = low + (high - low) / 2;
			if (isBadVersion(mid))
					high = mid;
			else
				low = mid + 1;
		}
		
		return high;
	}
};