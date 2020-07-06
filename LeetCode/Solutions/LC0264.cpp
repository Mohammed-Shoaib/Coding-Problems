/*
Problem Statement: https://leetcode.com/problems/ugly-number-ii/
Time: O(n • k)
Space: O(k)
*/

class Solution {
public:
	int nthUglyNumber(int n) {
		vector<int> fact = {2, 3, 5};
		int k = fact.size();
		vector<int> dp(n), idx(k);
		dp[0] = 1;

		// dynamic programming
		for (int i = 1; i < n; i++) {
			int mn = numeric_limits<int>::max();
			for (int j = 0; j < k; j++)
				mn = min(fact[j] * dp[idx[j]], mn);
			dp[i] = mn;
			for (int j = 0; j < k; j++)
				idx[j] += (fact[j] * dp[idx[j]] == mn);
		}

		return dp[n - 1];
	}
};