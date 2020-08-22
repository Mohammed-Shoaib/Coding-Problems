/*
Problem Statement: https://leetcode.com/problems/largest-divisible-subset/
Time: O(n²)
Space: O(n)
Author: Mohammed Shoaib, github.com/Mohammed-Shoaib
*/

class Solution {
public:
	vector<int> largestDivisibleSubset(vector<int>& nums) {
		int n = nums.size();
		vector<int> dp(n);
		
		if (nums.empty())
			return {};
		sort(nums.begin(), nums.end());
		
		// dynamic programming
		for (int i = 0; i < n; i++)
			for (int j = 0; j < i; j++)
				if (nums[i] % nums[j] == 0)
					dp[i] = max(dp[j] + 1, dp[i]);
		
		// backtrack
		int pos = distance(dp.begin(), max_element(dp.begin(), dp.end()));
		vector<int> subset = {nums[pos]};
		for (int i = n - 1; i >= 0; i--)
			if (subset.back() % nums[i] == 0 && dp[i] == dp[pos] - 1) {
				pos = i;
				subset.push_back(nums[i]);
			}
		
		return subset;
	}
};