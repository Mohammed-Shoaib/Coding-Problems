/*
Problem Statement: https://leetcode.com/problems/max-consecutive-ones-iii/
Time: O(n)
Space: O(1)
Author: Mohammed Shoaib, github.com/Mohammed-Shoaib
*/

class Solution {
public:
	int longestOnes(vector<int>& nums, int k) {
		int ones = 0, n = nums.size();
		
		for (int i = 0, j = 0; i < n; i++) {
			if (nums[i] == 0)
				k--;
			if (k < 0 && nums[j++] == 0)
				k++;
			ones = max(i - j + 1, ones);
		}
		
		return ones;
	}
};