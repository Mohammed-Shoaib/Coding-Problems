/*
Problem Statement: https://leetcode.com/problems/combination-sum-iv/
Time: O(target • n)
Space: O(target)
Author: Mohammed Shoaib, github.com/Mohammed-Shoaib
*/

class Solution {
public:
	int combinationSum4(vector<int>& nums, int target) {
		vector<unsigned int> dp(target + 1);
		
		// dynamic programming
		dp[0] = 1;
		for (int i = 0; i <= target; i++)
			for (int& x: nums)
				if (i - x >= 0)
					dp[i] += dp[i - x];
		
		return dp[target];
	}
};