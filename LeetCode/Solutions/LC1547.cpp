/*
Problem Statement: https://leetcode.com/problems/minimum-cost-to-cut-a-stick/
Time: O(m³)
Space: O(m²)
Author: Mohammed Shoaib, github.com/Mohammed-Shoaib
*/

class Solution {
public:
	int minCost(int n, vector<int>& cuts) {
		// preprocess
		cuts.push_back(0);
		cuts.push_back(n);
		sort(cuts.begin(), cuts.end());
		
		int m = cuts.size();
		vector<vector<int>> dp(m, vector<int>(m, numeric_limits<int>::max()));
		
		// initialization
		for (int i = 0; i < m - 1; i++)
			dp[i][i + 1] = 0;
		
		// dynamic programming
		for (int i = m - 1; i >= 0; i--)
			for (int j = i + 1; j < m; j++)
				for (int k = i + 1; k < j; k++)
					dp[i][j] = min(cuts[j] - cuts[i] + dp[i][k] + dp[k][j], dp[i][j]);
		
		return dp[0][m - 1];
	}
};