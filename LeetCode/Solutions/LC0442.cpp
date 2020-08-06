/*
Problem Statement: https://leetcode.com/problems/find-all-duplicates-in-an-array/
Time: O(n)
Space: O(1)
Author: Mohammed Shoaib, github.com/Mohammed-Shoaib
*/

class Solution {
public:
	vector<int> findDuplicates(vector<int>& nums) {
		int n = nums.size();
		vector<int> dups;
		
		for (int i = 0; i < n; i++) {
			int x = abs(nums[i]) - 1;
			if (nums[x] < 0)
				dups.push_back(x + 1);
			nums[x] *= -1;
		}
		for (int& num: nums)
			if (num < 0)
				num *= -1;
		
		return dups;
	}
};