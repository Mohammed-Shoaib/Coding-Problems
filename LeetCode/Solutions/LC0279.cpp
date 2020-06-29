/*
Problem Statement: https://leetcode.com/problems/perfect-squares/
Time Complexity: O(n * sqrt(n))
Space Complexity: O(n)
*/

class Solution {
public:
	int numSquares(int n) {
		vector<int> dp(n + 1, n);
		
		// dynamic programming
		dp[0] = 0;
		for (int i = 1; i <= n; i++)
			for (int j = 1; j * j <= i; j++)
				dp[i] = min(dp[i - j * j] + 1, dp[i]);
		
		return dp[n];
	}
};