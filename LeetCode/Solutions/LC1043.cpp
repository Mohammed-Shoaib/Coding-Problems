/*
Problem Statement: https://leetcode.com/problems/partition-array-for-maximum-sum/
Time: O(n • k)
Space: O(n)
Author: Mohammed Shoaib, github.com/Mohammed-Shoaib
*/

class Solution {
public:
	int maxSumAfterPartitioning(vector<int>& arr, int k) {
		int n = arr.size();
		vector<int> dp(n + 1);
		
		// dynamic programming
		for (int i = 1; i <= n; i++)
			for (int j = i, mx = 0; j <= min(n, i + k - 1); j++) {
				mx = max(arr[j - 1], mx);
				dp[j] = max(dp[i - 1] + mx * (j - i + 1), dp[j]);
			}
		
		return dp[n];
	}
};