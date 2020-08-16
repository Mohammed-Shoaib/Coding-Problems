/*
Problem Statement: https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-transaction-fee/
Time: O(n)
Space: O(1)
Author: Mohammed Shoaib, github.com/Mohammed-Shoaib
*/

class Solution {
public:
	int maxProfit(vector<int>& prices, int fee) {
		int n = prices.size();
		vector<int> prev, dp(2);

		// initialization
		dp[0] = numeric_limits<int>::min();

		// dynamic programming
		for (int& price: prices) {
			prev = dp;
			dp[0] = max(prev[1] - price - fee, prev[0]);
			dp[1] = max(prev[0] + price, prev[1]);
		}

		return dp[1];
	}
};