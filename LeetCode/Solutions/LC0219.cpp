/*
Problem Statement: https://leetcode.com/problems/contains-duplicate-ii/
Time: O(n)
Space: O(k)
Author: Mohammed Shoaib, github.com/Mohammed-Shoaib
*/

class Solution {
public:
	bool containsNearbyDuplicate(vector<int>& nums, int k) {
		int n = nums.size();
		unordered_set<int> seen;
		for (int i = 0; i < n; i++) {
			if (!seen.insert(nums[i]).second)
				return true;
			else if (i >= k)
				seen.erase(nums[i - k]);
		}
		return false;
	}
};