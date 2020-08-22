/*
Problem Statement: https://leetcode.com/problems/single-number/
Time: O(n)
Space: O(1)
Author: Mohammed Shoaib, github.com/Mohammed-Shoaib
*/

class Solution {
public:
	int singleNumber(vector<int>& nums) {
		int res = 0;
		for (int num: nums)
			res ^= num;
		return res;
	}
};