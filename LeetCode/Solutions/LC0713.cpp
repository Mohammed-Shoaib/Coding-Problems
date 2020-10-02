/*
Problem Statement: https://leetcode.com/problems/subarray-product-less-than-k/
Time: O(n)
Space: O(1)
Author: Mohammed Shoaib, github.com/Mohammed-Shoaib
*/

class Solution {
public:
	int numSubarrayProductLessThanK(vector<int>& nums, int k) {
		int cnt = 0, prod = 1, n = nums.size();
		for (int i = 0, j = 0; j < n; j++) {
			prod *= nums[j];
			while (i <= j && prod >= k)
				prod /= nums[i++];
			cnt += j - i + 1;
		}
		return cnt;
	}
};