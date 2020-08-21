/*
Problem Statement: https://leetcode.com/problems/subarray-sum-equals-k/
Time: O(n)
Space: O(n)
Author: Mohammed Shoaib, github.com/Mohammed-Shoaib
*/

class Solution {
public:
	int subarraySum(vector<int>& nums, int k) {
		int cnt, sum, n;
		unordered_map<int, int> freq;
		cnt = sum = 0;
		n = nums.size();
		freq[0]++;
		
		for (int i = 0; i < n; i++) {
			sum += nums[i];
			cnt += freq[sum - k];
			freq[sum]++;
		}
		
		return cnt;
	}
};