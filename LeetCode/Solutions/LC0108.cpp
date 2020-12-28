/*
Problem Statement: https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/
Time: O(n)
Space: O(n)
Author: Mohammed Shoaib, github.com/Mohammed-Shoaib
*/

class Solution {
public:
	TreeNode* sortedArrayToBST(vector<int>& nums) {
		return convert(0, nums.size(), nums);
	}
	
	TreeNode* convert(int low, int high, vector<int>& nums) {
		int mid = low + (high - low) / 2;
		if (low >= high)
			return nullptr;
		else
			return new TreeNode(nums[mid], convert(low, mid, nums), convert(mid + 1, high, nums));
	}
};