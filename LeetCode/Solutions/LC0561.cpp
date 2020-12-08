/*
Problem Statement: https://leetcode.com/problems/array-partition-i/
Time: O(n • log n)
Space: O(n)
Author: Mohammed Shoaib, github.com/Mohammed-Shoaib
*/

class Solution {
public:
	int arrayPairSum(vector<int> nums) {
		int sum = 0, n = nums.size();
		
		sort(nums.begin(), nums.end());
		for (int i = 0; i < n; i += 2)
			sum += nums[i];
		
		return sum;
	}
};