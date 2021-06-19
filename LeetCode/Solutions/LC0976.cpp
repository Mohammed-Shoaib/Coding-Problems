/*
Problem Statement: https://leetcode.com/problems/largest-perimeter-triangle/
Time: O(n • log n)
Space: O(n)
Author: Mohammed Shoaib, github.com/Mohammed-Shoaib
*/

class Solution {
public:
	int largestPerimeter(vector<int> nums) {
		int n = nums.size();
		sort(nums.begin(), nums.end());
		
		for (int i = n - 3; i >= 0; i--)
			if (nums[i] + nums[i + 1] > nums[i + 2])
				return accumulate(nums.begin() + i, nums.begin() + i + 3, 0);
		
		return 0;
	}
};