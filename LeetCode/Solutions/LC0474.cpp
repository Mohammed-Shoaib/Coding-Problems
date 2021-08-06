/*
Problem Statement: https://leetcode.com/problems/ones-and-zeroes/
Time: O(l • (m • n + max_len))
Space: O(m • n)
Author: Mohammed Shoaib, github.com/Mohammed-Shoaib
*/

class Solution {
public:
	int findMaxForm(vector<string>& strs, int m, int n) {
		int l = strs.size();
		vector<vector<int>> dp(m + 1, vector<int>(n + 1));
		
		// dynamic programming
		for (string& s: strs) {
			vector<int> cnt(2);
			cnt[0] = count(s.begin(), s.end(), '0');
			cnt[1] = s.length() - cnt[0];
			
			for (int j = m; j >= cnt[0]; j--)
				for (int k = n; k >= cnt[1]; k--)
					dp[j][k] = max(dp[j - cnt[0]][k - cnt[1]] + 1, dp[j][k]);
		}
		
		return dp[m][n];
	}
};