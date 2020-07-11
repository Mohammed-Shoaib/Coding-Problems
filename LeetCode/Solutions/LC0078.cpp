/*
Problem Statement: https://leetcode.com/problems/subsets/
Time: O(n • 2ⁿ)
Space: O(n • 2ⁿ)
Author: Mohammed Shoaib, github.com/Mohammed-Shoaib
*/

class Solution {
public:
	vector<vector<int>> subsets(vector<int>& nums) {
		int n = nums.size();
		vector<vector<int>> sets(1 << n);

		for (int b = 0; b < sets.size(); b++)
			for (int i = 0; i < n; i++)
				if ((b >> i) & 1)
					sets[b].push_back(nums[i]);
		
		return sets;
	}
};