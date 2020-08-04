/*
Problem Statement: https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/
Time: O(n)
Space: O(1)
Author: Mohammed Shoaib, github.com/Mohammed-Shoaib
*/

class Solution {
public:
	int maxProfit(vector<int>& prices) {
		int profit = 0;
		for (int i = 1; i < prices.size(); i++)
			profit += max(0, prices[i] - prices[i - 1]);
		return profit;
	}
};