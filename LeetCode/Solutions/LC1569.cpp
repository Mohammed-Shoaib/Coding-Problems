/*
Problem Statement: https://leetcode.com/problems/number-of-ways-to-reorder-array-to-get-same-bst/
Time: O(n²)
Space: O(n)
Author: Mohammed Shoaib, github.com/Mohammed-Shoaib
*/

class Solution {
private:
	const int mod = 1e9 + 7;
	vector<int64_t> fact, inv_fact;
public:
	int numOfWays(vector<int>& nums) {
		int n = nums.size(), m = 2 * n;
		fact = vector<int64_t>(m + 1);
		inv_fact = vector<int64_t>(m + 1);
		
		// precompute the factorials & inverse factorials
		fact[0] = 1;
		for (int i = 1; i <= m; i++)
			fact[i] = i * fact[i - 1] % mod;
		inv_fact[m] = mod_power(fact[m], mod - 2);
		for (int i = m - 1; i >= 0; i--)
			inv_fact[i] = (i + 1) * inv_fact[i + 1] % mod;
		
		return dfs(nums) - 1;
	}
	
	int mod_power(int64_t x, int n) {
		int y = 1;
		while (n) {
			if (n & 1)
				y = (y * x) % mod;
			n >>= 1;
			x = (x * x) % mod;
		}
		return y;
	}
	
	int nCr(int n, int r) {
		return (fact[n] * inv_fact[n - r] % mod) * inv_fact[r] % mod;
	}
	
	int64_t dfs(vector<int>& nums) {
		int n = nums.size();
		vector<int> l, r;
		
		if (n <= 1)
			return 1;
		
		for (int i = 1; i < n; i++) {
			if (nums[i] < nums[0])
				l.push_back(nums[i]);
			else
				r.push_back(nums[i]);
		}
		
		return (dfs(l) * dfs(r) % mod) * nCr(l.size() + r.size(), r.size()) % mod;
	}
};