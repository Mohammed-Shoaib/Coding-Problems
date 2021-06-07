/*
Problem Statement: https://leetcode.com/problems/min-cost-climbing-stairs/
Time: O(n)
Space: O(1)
Author: Mohammed Shoaib, github.com/Mohammed-Shoaib
*/

class Solution {
public:
	int minCostClimbingStairs(vector<int>& cost) {
		int prev = 0, dp = 0, n = cost.size();
		
		// dynamic programming
		for (int i = 2; i <= n; i++)
			dp = min(dp + cost[i - 1], exchange(prev, dp) + cost[i - 2]);
		
		return dp;
	}
};