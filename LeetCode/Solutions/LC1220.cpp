/*
Problem Statement: https://leetcode.com/problems/count-vowels-permutation/
Time: O(n)
Space: O(n + k)
Author: Mohammed Shoaib, github.com/Mohammed-Shoaib
*/

class Solution {
public:
	int countVowelPermutation(int n) {
		const int mod = 1e9 + 7;
		vector<int64_t> prev(5), dp(5, 1);
		
		// Recursion
		// {a: 0, e: 1, i: 2, o: 3, u: 4}
		for (int i = 1; i < n; i++) {
			prev = dp;
			dp[0] = (prev[1] + prev[2] + prev[4]) % mod;
			dp[1] = (prev[0] + prev[2]) % mod;
			dp[2] = (prev[1] + prev[3]) % mod;
			dp[3] = prev[2];
			dp[4] = (prev[2] + prev[3]) % mod;
		}
		
		return accumulate(dp.begin(), dp.end(), 0LL) % mod;
	}
};