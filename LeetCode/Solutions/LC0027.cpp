/*
Problem Statement: https://leetcode.com/problems/remove-element/
Time: O(n)
Space: O(1)
Author: Mohammed Shoaib, github.com/Mohammed-Shoaib
*/

class Solution {
public:
	int removeElement(vector<int>& nums, int val) {
		int pos = 0;
		
		for (int& x: nums)
			if (x != val)
				nums[pos++] = x;
		
		return pos;
	}
};