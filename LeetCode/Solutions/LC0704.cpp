/*
Problem Statement: https://leetcode.com/problems/binary-search/
Time: O(log n)
Space: O(1)
Author: Mohammed Shoaib, github.com/Mohammed-Shoaib
*/

class Solution {
public:
	int search(vector<int>& nums, int target) {
		int low = 0, high = nums.size();
		
		// binary search
		while (low < high) {
			int mid = low + (high - low) / 2;
			if (nums[mid] == target)
				return mid;
			else if (nums[mid] < target)
				low = mid + 1;
			else
				high = mid;
		}
		
		return -1;
	}
};