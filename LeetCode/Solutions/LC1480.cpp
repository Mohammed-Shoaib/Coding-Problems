/*
Problem Statement: https://leetcode.com/problems/running-sum-of-1d-array/
Time: O(n)
Space: O(n)
Author: Mohammed Shoaib, github.com/Mohammed-Shoaib
*/

class Solution {
public:
	vector<int> runningSum(vector<int> nums) {
		int n = nums.size();
		for (int i = 1; i < n; i++)
			nums[i] += nums[i - 1];
		return nums;
	}
};