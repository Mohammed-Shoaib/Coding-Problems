/*
Problem Statement: https://leetcode.com/problems/longest-harmonious-subsequence/
Time: O(n)
Space: O(n)
Author: Mohammed Shoaib, github.com/Mohammed-Shoaib
*/

class Solution {
public:
	int findLHS(vector<int>& nums) {
		int lhs = 0;
		unordered_map<int, int> freq;
		
		for (int& x: nums)
			freq[x]++;
		
		for (auto& [k, v]: freq)
			if (freq.count(k + 1))
				lhs = max(freq[k] + freq[k + 1], lhs);
		
		return lhs;
	}
};