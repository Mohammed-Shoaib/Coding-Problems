/*
Problem Statement: https://leetcode.com/problems/number-of-ways-to-stay-in-the-same-place-after-some-steps/
*/

class Solution {
public:
	int numWays(int steps, int arrLen) {
		int mod, n;
		mod = 1e9 + 7;
		n = min(steps / 2 + 1, arrLen);		// Minimum length to come back to position 0 or the length of the array
		vector<int> curr(n + 2), prev(n + 2);
		
		// Dynamic Programming
		prev[1] = 1;
		for (int i = 1; i <= steps; i++) {
			for (int j = 1; j <= n; j++)
				curr[j] = ((prev[j - 1] + prev[j]) % mod + prev[j + 1]) % mod;
			prev = curr;
		}

		return curr[1];
	}
};