/*
Problem Statement: https://leetcode.com/problems/first-bad-version/
*/

class Solution {
public:
	int firstBadVersion(int n) {
		int mid, low = 1, high = n;
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