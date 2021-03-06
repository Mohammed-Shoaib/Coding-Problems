/*
Problem Statement: https://leetcode.com/problems/find-minimum-in-rotated-sorted-array-ii/
Time: O(n)
Space: O(1)
Author: Mohammed Shoaib, github.com/Mohammed-Shoaib
*/

class Solution {
public:
	int findMin(vector<int>& nums) {
		int low, mid, high;
		low = 0;
		high = (int) nums.size() - 1;
		
		while (low < high) {
			mid = low + (high - low) / 2;
			if (nums[mid] < nums[high])
				high = mid;
			else if (nums[mid] > nums[high])
				low = mid + 1;
			else
				high--;
		}
		
		return nums[high];
	}
};