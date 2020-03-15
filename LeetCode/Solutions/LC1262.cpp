/*
Problem Statement: https://leetcode.com/problems/greatest-sum-divisible-by-three/
*/

class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {
		int mod, n, sum;
		mod = 3;
		n = nums.size();
		vector<int> prev(mod), dp(mod);

		// Dynamic Programming
		for (int i = 0; i < nums.size(); i++, prev = dp)
			for (int j = 0; j < prev.size(); j++) {
				sum = nums[i] + prev[j];
				dp[sum % mod] = max(sum, dp[sum % mod]);
			}
		
		return dp[0];
    }
};