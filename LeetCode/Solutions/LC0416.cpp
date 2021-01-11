/*
Problem Statement: https://leetcode.com/problems/partition-equal-subset-sum/
Time: O(n • sum)
Space: O(sum)
Author: Mohammed Shoaib, github.com/Mohammed-Shoaib
*/

class Solution {
public:
	bool canPartition(vector<int>& nums) {
		int n, sum;
		n = nums.size();
		sum = accumulate(nums.begin(), nums.end(), 0);
		vector<bool> dp(sum + 1);
		
		// base cases
		if (sum & 1)
			return false;
		dp[0] = true;
		
		// dynamic programming
		for (int& x: nums)
			for (int i = sum; i >= 0; i--)
				if (dp[i])
					dp[i + x] = true;
		
		return dp[sum / 2];
	}
};