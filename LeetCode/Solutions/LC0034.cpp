/*
Problem Statement: https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/
Time: O(log n)
Space: O(1)
Author: Mohammed Shoaib, github.com/Mohammed-Shoaib
*/

class Solution {
public:
	vector<int> searchRange(vector<int>& nums, int target) {
		// use 2 binary searches
		int beg, end;
		beg = lower_bound(nums, target);
		end = upper_bound(nums, target) - 1;
		if (beg == nums.size() || nums[beg] != target)
			return {-1, -1};
		else
			return {beg, end};
	}
	
	int lower_bound(vector<int>& nums, int target) {
		int low = 0, high = nums.size();
		while (low < high) {
			int mid = low + (high - low) / 2;
			if (nums[mid] < target)
				low = mid + 1;
			else
				high = mid;
		}
		return low;
	}
	
	int upper_bound(vector<int>& nums, int target) {
		int low = 0, high = nums.size();
		while (low < high) {
			int mid = low + (high - low) / 2;
			if (nums[mid] > target)
				high = mid;
			else
				low = mid + 1;
		}
		return high;
	}
};