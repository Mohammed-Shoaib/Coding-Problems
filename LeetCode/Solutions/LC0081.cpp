/*
Problem Statement: https://leetcode.com/problems/search-in-rotated-sorted-array-ii/
Time: O(n)
Space: O(1)
Author: Mohammed Shoaib, github.com/Mohammed-Shoaib
*/

class Solution {
public:
	bool search(vector<int>& nums, int target) {
		int low, mid, high;
		low = 0;
		high = (int) nums.size() - 1;

		// binary search
		while (low < high) {
			mid = (low + high) / 2;
			if (nums[mid] == nums[high])
				high--;
			else if ((nums[0] > target) ^ (target > nums[mid]) ^ (nums[0] > nums[mid]))
				low = mid + 1;
			else
				high = mid;
		}

		return !nums.empty() && nums[high] == target;
	}
};