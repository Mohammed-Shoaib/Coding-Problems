/*
Problem Statement: https://leetcode.com/problems/find-the-smallest-divisor-given-a-threshold/
Time: O(n • log n)
Space: O(1)
Author: Mohammed Shoaib, github.com/Mohammed-Shoaib
*/

class Solution {
public:
	int smallestDivisor(vector<int>& nums, int threshold) {
		int n, low, mid, high;
		n = nums.size();
		low = 1;
		high = *max_element(nums.begin(), nums.end());
		
		// helper function
		auto good = [&](int x) {
			int sum = 0;
			for (int i = 0; i < n; i++)
				sum += (nums[i] + x - 1) / x;
			return sum > threshold;	
		};
		
		// binary search
		while (low < high) {
			mid = low + (high - low) / 2;
			if (good(mid))
				low = mid + 1;
			else
				high = mid;
		}
		
		return high;
	}
};