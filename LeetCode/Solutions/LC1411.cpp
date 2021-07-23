/*
Problem Statement: https://leetcode.com/problems/number-of-ways-to-paint-n-3-grid/
*/

class Solution {
public:
	int numOfWays(int n) {
		int mod = 1e9 + 7;
		long long colors_3, colors_2, prev_3, prev_2;
		prev_3 = prev_2 = 6;

		for (int i = 1; i <= n; i++) {
			colors_3 = prev_3 % mod;
			colors_2 = prev_2 % mod;
			prev_3 = 2 * (colors_3 + colors_2);
			prev_2 = 2 * colors_3 + 3 * colors_2;
		}

		return (colors_3 + colors_2) % mod;
	}
};