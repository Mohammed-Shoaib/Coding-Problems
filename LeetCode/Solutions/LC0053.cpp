/*
Problem Statement: https://leetcode.com/problems/maximum-subarray/
*/

class Solution {
public:
	int maxSubArray(vector<int>& nums) {
		int max_sum, sum;
		max_sum = sum = nums[0];
		for (int i = 1; i < nums.size(); i++) {
			sum = max(nums[i], sum + nums[i]);
			max_sum = max(sum, max_sum);
		}
		return max_sum;
	}
};