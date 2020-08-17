/*
Problem Statement: https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iv/
Time: O(n • k)
Space: O(k)
Author: Mohammed Shoaib, github.com/Mohammed-Shoaib
*/

class Solution {
public:
	int maxProfit(int k, vector<int>& prices) {
		// choose freely
		if (k >= prices.size() / 2)
			return maxProfit(prices);
		
		vector<vector<int>> dp(k + 1, {numeric_limits<int>::min(), 0});
		
		// dynamic programming
		for (int& price: prices)
			for (int i = 1; i <= k; i++) {
				dp[i][0] = max(dp[i - 1][1] - price, dp[i][0]);
				dp[i][1] = max(dp[i][0] + price, dp[i][1]);
			}
		
		return dp[k][1];
	}

	int maxProfit(vector<int>& prices) {
		int profit = 0;
		for (int i = 1; i < prices.size(); i++)
			profit += max(0, prices[i] - prices[i - 1]);
		return profit;
	}
};