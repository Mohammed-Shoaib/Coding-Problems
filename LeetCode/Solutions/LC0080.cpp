/*
Problem Statement: https://leetcode.com/problems/remove-duplicates-from-sorted-array-ii/
Time: O(n)
Space: O(1)
Author: Mohammed Shoaib, github.com/Mohammed-Shoaib
*/

class Solution {
public:
	int removeDuplicates(vector<int>& nums) {
		int k = 2, pos = k, n = nums.size();
		
		for (int i = k; i < n; i++)
			if (nums[pos - k] < nums[i])
				nums[pos++] = nums[i];
		
		return min(pos, n);
	}
};