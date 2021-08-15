/*
Problem Statement: https://leetcode.com/problems/partition-to-k-equal-sum-subsets/
Time: O(n • 2ⁿ)
Space: O(2ⁿ)
Author: Mohammed Shoaib, github.com/Mohammed-Shoaib
*/

class Solution {
public:
	bool canPartitionKSubsets(vector<int>& nums, int k) {
		int n, m, sum;
		n = nums.size();
		m = 1 << n;
		sum = accumulate(nums.begin(), nums.end(), 0);
		vector<int> dp(m, -1);
		
		// base case
		if (sum % k != 0)
			return false;
		sum /= k;
		
		// dynamic programming
		dp[0] = 0;
		for (int b = 0; b < m; b++) {
			if (dp[b] == -1)
				continue;
			for (int i = 0; i < n; i++) {
				if ((b >> i) & 1 || dp[b] + nums[i] > sum)
					continue;
				dp[b | (1 << i)] = (dp[b] + nums[i]) % sum;
			}
		}
		
		return dp[m - 1] == 0;
	}
};