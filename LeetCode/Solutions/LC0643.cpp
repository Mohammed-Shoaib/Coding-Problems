/*
Problem Statement: https://leetcode.com/problems/maximum-average-subarray-i/
*/

class Solution {
public:
	double findMaxAverage(vector<int>& nums, int k) {
		double max_sum, sum;
		max_sum = sum = accumulate(nums.begin(), nums.begin() + k, 0);
		for (int i = k; i < nums.size(); i++) {
			sum += nums[i] - nums[i - k];
			max_sum = max(sum, max_sum);
		}
		return max_sum / k;
	}
};