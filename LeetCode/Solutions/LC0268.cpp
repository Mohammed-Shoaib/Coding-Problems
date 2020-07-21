/*
Problem Statement: https://leetcode.com/problems/missing-number/
Time: O(n)
Space: O(1)
Author: Mohammed Shoaib, github.com/Mohammed-Shoaib
*/

class Solution {
public:
	int missingNumber(vector<int>& nums) {
		int b = nums.size();
		for (int i = 0; i < nums.size(); i++)
			b ^= i ^ nums[i];
		return b;
	}
};