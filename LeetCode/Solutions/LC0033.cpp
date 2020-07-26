/*
Problem Statement: https://leetcode.com/problems/search-in-rotated-sorted-array/
Time: O(log n)
Space: O(1)
Author: Mohammed Shoaib, github.com/Mohammed-Shoaib
*/

class Solution {
public:
	int search(vector<int>& nums, int target) {
		int low, mid, high;
		low = 0;
		high = (int) nums.size() - 1;
		
		// binary search
		while (low < high) {
			mid = low + (high - low) / 2;
			if ((nums[0] > target) ^ (target > nums[mid]) ^ (nums[0] > nums[mid]))
				low = mid + 1;
			else
				high = mid;
		}
		
		return (!nums.empty() && nums[high] == target) ? high : -1;
	}
};