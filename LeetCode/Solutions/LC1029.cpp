/*
Problem Statement: https://leetcode.com/problems/two-city-scheduling/
Time: O(n • log n)
Space: O(1)
Author: Mohammed Shoaib, github.com/Mohammed-Shoaib
*/

class Solution {
public:
	int twoCitySchedCost(vector<vector<int>> costs) {
		int min_cost, n;
		min_cost = 0;
		n = costs.size();
		
		sort(costs.begin(), costs.end(), [](auto& l, auto& r) {
			return l[0] - l[1] < r[0] - r[1];
		});
		
		for (int i = 0; i < n; i++)
			min_cost += costs[i][i >= n / 2];
		
		return min_cost;
	}
};