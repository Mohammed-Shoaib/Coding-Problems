/*
Problem Statement: https://leetcode.com/problems/coin-change-2/
Time: O(coins + amount)
Space: O(amount)
Author: Mohammed Shoaib, github.com/Mohammed-Shoaib
*/

class Solution {
public:
	int change(int amount, vector<int>& coins) {
		vector<int> dp(amount + 1);
		
		// dynamic programming
		dp[0] = 1;
		for (int coin: coins)
			for (int j = coin; j <= amount; j++)
				dp[j] += dp[j - coin];
		
		return dp[amount];
	}
};