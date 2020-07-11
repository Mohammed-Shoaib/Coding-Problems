/*
Problem Statement: https://leetcode.com/problems/subsets-ii/
Time: O(n • 2ⁿ)
Space: O(n • 2ⁿ)
Author: Mohammed Shoaib, github.com/Mohammed-Shoaib
*/

class Solution {
public:
	vector<vector<int>> subsetsWithDup(vector<int>& nums) {
		vector<int> subset;
		vector<vector<int>> subsets;
		sort(nums.begin(), nums.end());
		generate_subset(0, nums, subset, subsets);
		return subsets;
	}

	void generate_subset(int pos, vector<int>& nums, vector<int>& subset, vector<vector<int>>& subsets) {
		subsets.push_back(subset);
		for (int i = pos; i < nums.size(); i++) {
			if (i > pos && nums[i - 1] == nums[i])
				continue;
			subset.push_back(nums[i]);
			generate_subset(i + 1, nums, subset, subsets);
			subset.pop_back();
		}
	}
};