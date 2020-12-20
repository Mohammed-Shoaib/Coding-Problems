/*
Problem Statement: https://leetcode.com/problems/peak-index-in-a-mountain-array/
Time: O(log n)
Space: O(1)
Author: Mohammed Shoaib, github.com/Mohammed-Shoaib
*/

class Solution {
public:
	int peakIndexInMountainArray(vector<int>& A) {
		int mid, low = 0, high = A.size() - 1;
		while (low < high) {
			mid = low + (high - low) / 2;
			if (A[mid] > A[mid + 1])
				high = mid;
			else
				low = mid + 1;
		}
		return high;
	}
};