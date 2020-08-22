/*
Problem Statement: https://leetcode.com/problems/contiguous-array/
Time: O(n)
Space: O(n)
Author: Mohammed Shoaib, github.com/Mohammed-Shoaib
*/

class Solution {
public:
	int findMaxLength(vector<int>& nums) {
		int max_l, sum, n;
		unordered_map<int, int> m;
		max_l = sum = 0;
		n = nums.size();
		m[sum] = -1;
		
		for (int i = 0; i < n; i++) {
			sum += (nums[i] == 0) ? -1 : 1;
			if (m.count(sum))
				max_l = max(i - m[sum], max_l);
			else
				m[sum] = i;
		}
		
		return max_l;
	}
};