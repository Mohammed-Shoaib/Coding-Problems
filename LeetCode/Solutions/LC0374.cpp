/*
Problem Statement: https://leetcode.com/problems/guess-number-higher-or-lower/
Time: O(log n)
Space: O(1)
Author: Mohammed Shoaib, github.com/Mohammed-Shoaib
*/

class Solution {
public:
	int guessNumber(int n) {
		int low = 1, high = n;
		
		// binary search
		while (low <= high) {
			int mid, res;
			mid = low + (high - low) / 2;
			res = guess(mid);
			
			if (res == 0)
				return mid;
			else if (res < 0)
				high = mid - 1;
			else
				low = mid + 1;
		}
		
		return -1;
	}
};