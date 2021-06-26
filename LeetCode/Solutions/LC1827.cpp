/*
Problem Statement: https://leetcode.com/problems/minimum-operations-to-make-the-array-increasing/
Time: O(n)
Space: O(1)
Author: Mohammed Shoaib, github.com/Mohammed-Shoaib
*/

class Solution {
public:
	int minOperations(vector<int>& nums) {
		int cnt, prev, n;
		cnt = 0;
		prev = nums[0];
		n = nums.size();
		
		for (int i = 1; i < n; i++) {
			if (prev >= nums[i])
				cnt += prev - nums[i] + 1;
			prev = max(nums[i], prev + 1);
		}
		
		return cnt;
	}
};