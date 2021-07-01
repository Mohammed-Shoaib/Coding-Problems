/*
Problem Statement: https://leetcode.com/problems/minimum-distance-to-the-target-element/
Time: O(n)
Space: O(1)
Author: Mohammed Shoaib, github.com/Mohammed-Shoaib
*/

class Solution {
public:
	int getMinDistance(vector<int>& nums, int target, int start) {
		int n = nums.size();
		
		for (int d = 0; start - d >= 0 || start + d < n; d++)
			if (start - d >= 0 && nums[start - d] == target ||
				start + d  < n && nums[start + d] == target)
				return d;
		
		return -1;
	}
};