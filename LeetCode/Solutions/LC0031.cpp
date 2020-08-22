/*
Problem Statement: https://leetcode.com/problems/next-permutation/
*/

class Solution {
public:
	void nextPermutation(vector<int>& nums) {
		int i, j, n;
		n = nums.size();
		
		for (i = n - 2; i >= 0; i--)
			if (nums[i] < nums[i + 1])
				break;
		
		if (i < 0) {
			reverse(nums.begin(), nums.end());
			return;
		}
		
		for (j = n - 1; j > i; j--)
			if (nums[i] < nums[j])
				break;
		
		swap(nums[i], nums[j]);
		reverse(nums.begin() + i + 1, nums.end());
	}
};