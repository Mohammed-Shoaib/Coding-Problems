/*
Problem Statement: https://leetcode.com/problems/find-peak-element/
Time: O(log n)
Space: O(1)
Author: Mohammed Shoaib, github.com/Mohammed-Shoaib
*/

class Solution {
public:
	int findPeakElement(vector<int>& nums) {
		int mid, low = 0, high = nums.size() - 1;
		while (low < high) {
			mid = low + (high - low) / 2;
			if (nums[mid] > nums[mid + 1])
				high = mid;
			else
				low = mid + 1;
		}
		return high;
	}
};