/*
Problem Statement: https://leetcode.com/problems/remove-duplicates-from-sorted-array/
Time: O(n)
Space: O(1)
Author: Mohammed Shoaib, github.com/Mohammed-Shoaib
*/

class Solution {
public:
	int removeDuplicates(vector<int>& nums) {
		int pos = 0;
		
		for (int& x: nums)
			if (nums[pos] != x)
				nums[++pos] = x;
		
		return pos + !nums.empty();
	}
};