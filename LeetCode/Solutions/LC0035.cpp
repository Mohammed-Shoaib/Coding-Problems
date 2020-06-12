/*
Problem Statement: https://leetcode.com/problems/search-insert-position/
*/

class Solution {
public:
	int searchInsert(vector<int>& nums, int target) {
		int low = 0, high = nums.size();
		while (low < high) {
			int mid = (low + high) / 2;
			if (nums[mid] >= target)
				high = mid;
			else
				low = mid + 1;
		}
		return high;
	}
};