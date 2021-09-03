/*
Problem Statement: https://leetcode.com/problems/range-sum-of-sorted-subarray-sums/
Time: O(n²)
Space: O(n²)
Author: Mohammed Shoaib, github.com/Mohammed-Shoaib
*/

class Solution {
public:
	int rangeSum(vector<int>& nums, int n, int left, int right) {
		int sum = 0, mod = 1e9 + 7;
		vector<int> sums;
		
		// preprocessing
		for (int i = 0; i < n; i++)
			for (int j = i, sum = 0; j < n; j++) {
				sum += nums[j];
				sums.push_back(sum);
			}
		sort(sums.begin(), sums.end());
		
		// compute the sum of the subarray
		for (int i = left - 1; i < right; i++)
			sum = (sum + sums[i]) % mod;
		
		return sum;
	}
};