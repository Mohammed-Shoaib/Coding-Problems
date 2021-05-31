/*
Problem Statement: https://leetcode.com/problems/maximum-gap/
Time: O(n • log max)
Space: O(n)
Author: Mohammed Shoaib, github.com/Mohammed-Shoaib
*/

class Solution {
private:
	void radix_sort(int n, vector<int>& nums) {
		int mod = 10, mx = *max_element(nums.begin(), nums.end());
		
		for (int64_t i = 1; mx / i > 0; i *= mod) {
			vector<int> freq(mod), arr(n);
			
			for (int& x: nums)
				freq[(x / i) % mod]++;
			
			for (int i = 1; i < mod; i++)
				freq[i] += freq[i - 1];
			
			for (int j = n - 1; j >= 0; j--)
				arr[--freq[(nums[j] / i) % mod]] = nums[j];
			
			nums = arr;
		}
	}
public:
	int maximumGap(vector<int>& nums) {
		int gap = 0, n = nums.size();
		radix_sort(n, nums);
		
		for (int i = 1; i < n; i++)
			gap = max(nums[i] - nums[i - 1], gap);
		
		return gap;
	}
};
