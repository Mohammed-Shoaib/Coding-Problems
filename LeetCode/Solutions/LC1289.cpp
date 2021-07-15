/*
Problem Statement: https://leetcode.com/problems/minimum-falling-path-sum-ii/
*/

class Solution {
public:
	int minFallingPathSum(vector< vector<int> >& arr) {
		int mn, n = arr.size();
		vector<int> pos(2), prev(2), dp(2);		// stores 1st and 2nd minimum and their positions
		
		// Dynamic Programming
		for (int i = 0; i < n; i++) {
			prev = dp;
			pos[0] = pos[1];
			dp[0] = dp[1] = numeric_limits<int>::max();
			
			for (int j = 0; j < n; j++) {
				if (j != pos[0])
					mn = arr[i][j] + prev[0];
				else
					mn = arr[i][j] + prev[1];
				if (mn < dp[0]) {
					dp[1] = dp[0];
					dp[0] = mn;
					pos[1] = j;
				}
				else if (mn <= dp[1])
					dp[1] = mn;
			}
		}

		return dp[0];
	}
};