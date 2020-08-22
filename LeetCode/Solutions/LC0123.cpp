/*
Problem Statement: https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/
Time: O(n)
Space: O(1)
Author: Mohammed Shoaib, github.com/Mohammed-Shoaib
*/

class Solution {
public:
	int maxProfit(vector<int>& prices) {
		vector<vector<int>> dp(2, {numeric_limits<int>::min(), 0});
		
		// dynamic programming
		for (int& price: prices) {
			dp[0][0] = max(         - price, dp[0][0]);
			dp[0][1] = max(dp[0][0] + price, dp[0][1]);
			dp[1][0] = max(dp[0][1] - price, dp[1][0]);
			dp[1][1] = max(dp[1][0] + price, dp[1][1]);
		}
		
		return dp[1][1];
	}
};