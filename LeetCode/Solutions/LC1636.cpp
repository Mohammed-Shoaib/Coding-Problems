/*
Problem Statement: https://leetcode.com/problems/sort-array-by-increasing-frequency/
Time: O(n • log n)
Space: O(n)
Author: Mohammed Shoaib, github.com/Mohammed-Shoaib
*/

class Solution {
public:
	vector<int> frequencySort(vector<int> nums) {
		int n = nums.size();
		unordered_map<int, int> freq;
		
		for (int& x: nums)
			freq[x]++;
		
		sort(nums.begin(), nums.end(), [&](int l, int r) {
			int cnt_l = freq[l], cnt_r = freq[r];
			if (cnt_l == cnt_r)
				return l > r;
			else
				return cnt_l < cnt_r;
		});
		
		return nums;
	}
};