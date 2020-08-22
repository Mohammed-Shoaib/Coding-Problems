/*
Problem Statement: https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/
Time: O(n)
Space: O(1)
Author: Mohammed Shoaib, github.com/Mohammed-Shoaib
*/

class Solution {
public:
	int maxProfit(vector<int>& prices) {
		int n = prices.size();
		vector<int> prev, dp(3);
		
		// initialization
		dp[1] = numeric_limits<int>::min();
		
		// dynamic programming
		for (int& price: prices) {
			prev = dp;
			dp[0] = max(prev[0], prev[2]);
			dp[1] = max(prev[0] - price, prev[1]);
			dp[2] = max(prev[1] + price, prev[2]);
		}
		
		return max(dp[0], dp[2]);
	}
};