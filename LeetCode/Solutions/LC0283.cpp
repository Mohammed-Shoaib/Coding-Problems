/*
Problem Statement: https://leetcode.com/problems/move-zeroes/
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