/*
Problem Statement: https://leetcode.com/problems/minimum-deletion-cost-to-avoid-repeating-letters/
Time: O(n)
Space: O(1)
Author: Mohammed Shoaib, github.com/Mohammed-Shoaib
*/

class Solution {
public:
	int minCost(string s, vector<int>& cost) {
		int mx, sum, min_cost = 0, n = s.length();
		for (int j, i = 0; i + 1 < n; i++) {
			if (s[i] != s[i + 1])
				continue;
			mx = sum = 0;
			for (j = i; j < n && s[j] == s[i]; j++) {
				sum += cost[j];
				mx = max(cost[j], mx);
			}
			min_cost += sum - mx;
			i = j - 1;
		}
		return min_cost;
	}
};