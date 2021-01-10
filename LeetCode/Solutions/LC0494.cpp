/*
Problem Statement: https://leetcode.com/problems/target-sum/
Time: O(n • k)
Space: O(n • k)
Author: Mohammed Shoaib, github.com/Mohammed-Shoaib
*/

class Solution {
public:
	int findTargetSumWays(vector<int>& nums, int S) {
		int n, k, sum;
		n = nums.size();
		sum = accumulate(nums.begin(), nums.end(), 0);
		k = 2 * sum + 1;
		
		// base cases
		if (S < -sum || S > sum)
			return 0;
		vector<int> prev, dp(k);
		dp[sum] = 1;
		
		// dynamic programming
		for (int& x: nums) {
			prev = exchange(dp, vector<int>(k));
			for (int i = 0; i < k; i++)
				if (prev[i]) {
					dp[i + x] += prev[i];
					dp[i - x] += prev[i];
				}
		}
		
		return dp[sum + S];
	}
};