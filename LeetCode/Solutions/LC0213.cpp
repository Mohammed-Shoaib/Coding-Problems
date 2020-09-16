/*
Problem Statement: https://leetcode.com/problems/house-robber-ii/
Time: O(n)
Space: O(1)
Author: Mohammed Shoaib, github.com/Mohammed-Shoaib
*/

class Solution {
public:
	int rob(vector<int>& nums) {
		int n = nums.size();
		if (n == 1)
			return nums[0];
		else
			return max(house_robber(0, n - 2, nums), house_robber(1, n - 1, nums));
	}
	
	int house_robber(int beg, int end, vector<int>& nums) {
		int prev, curr;
		prev = curr = 0;
		for (int i = beg; i <= end; i++)
			prev = exchange(curr, max(prev + nums[i], curr));
		return curr;
	}
};