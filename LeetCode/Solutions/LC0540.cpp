/*
Problem Statement: https://leetcode.com/problems/single-element-in-a-sorted-array/
Time: O(log n)
Space: O(1)
Author: Mohammed Shoaib, github.com/Mohammed-Shoaib
*/

class Solution {
public:
	int singleNonDuplicate(vector<int>& nums) {
		int mid, low = 0, high = nums.size() - 1;
		
		// binary search
		while (low < high) {
			mid = low + (high - low) / 2;
			if (nums[mid] == nums[mid ^ 1])
				low = mid + 1;
			else
				high = mid;
		}
		
		return nums[low];
	}
};