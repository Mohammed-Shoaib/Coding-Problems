/*
Problem Statement: https://leetcode.com/problems/number-of-subarrays-with-bounded-maximum/
Time: O(n)
Space: O(1)
Author: Mohammed Shoaib, github.com/Mohammed-Shoaib
*/

class Solution {
public:
	int numSubarrayBoundedMax(vector<int>& nums, int left, int right) {
		int cnt = 0, n = nums.size();
		
		for (int i = 0, l = -1, r = -1; i < n; i++) {
			if (nums[i] > right)
				l = i;
			if (nums[i] >= left)
				r = i;
			cnt += r - l;
		}
		
		return cnt;
	}
};