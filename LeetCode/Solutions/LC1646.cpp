/*
Problem Statement: https://leetcode.com/problems/get-maximum-in-generated-array/
Time: O(n)
Space: O(n)
Author: Mohammed Shoaib, github.com/Mohammed-Shoaib
*/

class Solution {
public:
	int getMaximumGenerated(int n) {
		// base case
		if (n <= 1)
			return n;
		
		vector<int> nums(n + 1);
		nums[1] = 1;
		
		for (int i = 2; i <= n; i++)
			nums[i] = nums[i >> 1] + nums[(i >> 1) + 1] * (i & 1);
		
		return *max_element(nums.begin(), nums.end());
	}
};