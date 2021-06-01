/*
Problem Statement: https://leetcode.com/problems/count-number-of-nice-subarrays/
Time: O(n)
Space: O(n)
Author: Mohammed Shoaib, github.com/Mohammed-Shoaib
*/

class Solution {
public:
	int numberOfSubarrays(vector<int>& nums, int k) {
		int nice = 0, cnt = 1, n = nums.size();
		vector<int> gaps;
		
		for (int i = 0; i < n; i++, cnt++)
			if (nums[i] & 1) {
				gaps.push_back(cnt);
				cnt = 0;
			}
		gaps.push_back(cnt);
		
		for (int i = 0; i + k < gaps.size(); i++)
			nice += gaps[i] * gaps[i + k];
		
		return nice;
	}
};