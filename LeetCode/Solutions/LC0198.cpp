/*
Problem Statement: https://leetcode.com/problems/house-robber/
Time: O(n)
Space: O(1)
Author: Mohammed Shoaib, github.com/Mohammed-Shoaib
*/

class Solution {
public:
	int rob(vector<int>& nums) {
		int prev, curr;
		prev = curr = 0;
		for (int& x: nums)
			prev = exchange(curr, max(prev + x, curr));
		return curr;
	}
};