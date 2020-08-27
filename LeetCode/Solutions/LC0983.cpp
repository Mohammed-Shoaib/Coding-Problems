/*
Problem Statement: https://leetcode.com/problems/minimum-cost-for-tickets/
Time: O(n)
Space: O(n)
Author: Mohammed Shoaib, github.com/Mohammed-Shoaib
*/

class Solution {
public:
	int mincostTickets(vector<int>& days, vector<int>& costs) {
		int n = days.back();
		vector<int> dp(n + 1);
		
		// initialization
		for (int& day: days)
			dp[day] = numeric_limits<int>::max();
		
		// dynamic programming
		for (int i = 1; i <= n; i++) {
			if (dp[i] == 0)
				dp[i] = dp[i - 1];
			else
				dp[i] = min({dp[i - 1         ] + costs[0],
							 dp[max(0, i -  7)] + costs[1],
							 dp[max(0, i - 30)] + costs[2]});
		}
		
		return dp[n];
	}
};