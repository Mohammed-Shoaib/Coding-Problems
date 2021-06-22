/*
Problem Statement: https://leetcode.com/problems/special-array-with-x-elements-greater-than-or-equal-x/
Time: O(n • log n)
Space: O(n)
Author: Mohammed Shoaib, github.com/Mohammed-Shoaib
*/

class Solution {
public:
	int specialArray(vector<int> nums) {
		int n = nums.size();
		sort(nums.begin(), nums.end());
		
		for (int i = 1; i <= n; i++) {
			int x = n - distance(nums.begin(), lower_bound(nums.begin(), nums.end(), i));
			if (x == i)
				return x;
		}
		
		return -1;
	}
};