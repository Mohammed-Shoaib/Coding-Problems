/*
Problem Statement: https://leetcode.com/problems/check-if-it-is-a-good-array/
Time: O(n)
Space: O(1)
Author: Mohammed Shoaib, github.com/Mohammed-Shoaib
*/

class Solution {
public:
	bool isGoodArray(vector<int>& nums) {
		int g = accumulate(nums.begin(), nums.end(), nums[0], gcd<int, int>);
		return g == 1; 
	}
};