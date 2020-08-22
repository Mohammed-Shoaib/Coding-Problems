/*
Problem Statement: https://leetcode.com/problems/toss-strange-coins/
Time: O(n • target)
Space: O(n • target)
Author: Mohammed Shoaib, github.com/Mohammed-Shoaib
*/

class Solution {
public:
	double probabilityOfHeads(vector<double>& prob, int target) {
		int n = prob.size();
		vector<vector<double>> dp(n + 1, vector<double>(target + 1));
		dp[0][0] = 1.0;
		
		for (int i = 1; i <= n; i++)
			for (int j = 0; j <= target; j++) {
				if (j == 0)
					dp[i][j] = dp[i - 1][j] * (1 - prob[i - 1]);
				else
					dp[i][j] = dp[i - 1][j] * (1 - prob[i - 1]) + dp[i - 1][j - 1] * prob[i - 1];
			}
		
		return dp[n][target];
	}
};