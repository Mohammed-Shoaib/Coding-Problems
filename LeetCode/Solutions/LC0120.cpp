/*
Problem Statement: https://leetcode.com/problems/triangle/
Time: O(n)
Space: O(n)
Author: Mohammed Shoaib, github.com/Mohammed-Shoaib
*/

class Solution {
public:
	int minimumTotal(vector<vector<int>>& triangle) {
		int n = triangle.size();
		vector<int> dp = triangle.back();
		
		// dynamic programming
		for (int i = n - 2; i >= 0; i--)
			for (int j = 0; j <= i; j++)
				dp[j] = triangle[i][j] + min(dp[j], dp[j + 1]);
		
		return dp[0];
	}
};