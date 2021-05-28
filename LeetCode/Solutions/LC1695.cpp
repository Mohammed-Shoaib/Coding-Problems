/*
Problem Statement: https://leetcode.com/problems/maximum-erasure-value/
Time: O(n)
Space: O(n)
Author: Mohammed Shoaib, github.com/Mohammed-Shoaib
*/

class Solution {
public:
	int maximumUniqueSubarray(vector<int>& nums) {
		int score = 0, n = nums.size();
		vector<int> prefix(n + 1);
		unordered_map<int, int> mp;
		
		// preprocess
		for (int i = 1; i <= n; i++)
			prefix[i] = nums[i - 1] + prefix[i - 1];
		
		// calculate maximum erasure value
		for (int i = 1, j = 0; i <= n; i++) {
			j = max(mp[nums[i - 1]], j);
			score = max(prefix[i] - prefix[j], score);
			mp[nums[i - 1]] = i;
		}
		
		return score;
	}
};