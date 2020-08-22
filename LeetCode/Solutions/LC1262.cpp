/*
Problem Statement: https://leetcode.com/problems/greatest-sum-divisible-by-three/
Time: O(n)
Space: O(1)
Author: Mohammed Shoaib, github.com/Mohammed-Shoaib
*/

class Solution {
public:
	int maxSumDivThree(vector<int>& nums) {
		int mod = 3, n = nums.size();
		vector<int> prev(mod), dp(mod);
		
		// dynamic programming
		for (int i = 0; i < n; i++, prev = dp)
			for (int j = 0; j < mod; j++) {
				int sum = nums[i] + prev[j];
				dp[sum % mod] = max(sum, dp[sum % mod]);
			}
		
		return dp[0];
	}
};