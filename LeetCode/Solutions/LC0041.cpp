/*
Problem Statement: https://leetcode.com/problems/first-missing-positive/
Time: O(n)
Space: O(n)
Author: Mohammed Shoaib, github.com/Mohammed-Shoaib
*/

class Solution {
public:
	int firstMissingPositive(vector<int> nums) {
		int n = nums.size();
		
		for (int i = 0; i < n; i++) {
			int& pos = nums[i];
			while (pos > 0 && pos <= n && pos != nums[pos - 1])
				swap(pos, nums[pos - 1]);
		}
		
		for (int i = 0; i < n; i++)
			if (nums[i] != i + 1)
				return i + 1;
		
		return n + 1;
	}
};