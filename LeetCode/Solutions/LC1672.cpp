/*
Problem Statement: https://leetcode.com/problems/richest-customer-wealth/
Time: O(m • n)
Space: O(1)
Author: Mohammed Shoaib, github.com/Mohammed-Shoaib
*/

class Solution {
public:
	int maximumWealth(vector<vector<int>>& accounts) {
		int max_wealth = 0;
		
		for (int i = 0; i < accounts.size(); i++) {
			int wealth = accumulate(accounts[i].begin(), accounts[i].end(), 0);
			max_wealth = max(wealth, max_wealth);
		}
		
		return max_wealth;
	}
};