/*
Problem Statement: https://leetcode.com/problems/move-zeroes/
Time: O(n)
Space: O(1)
Author: Mohammed Shoaib, github.com/Mohammed-Shoaib
*/

class Solution {
public:
	void moveZeroes(vector<int>& nums) {
		int j = 0;
		for (int num: nums)
			if (num)
				nums[j++] = num;
		fill(nums.begin() + j, nums.end(), 0);
	}
};