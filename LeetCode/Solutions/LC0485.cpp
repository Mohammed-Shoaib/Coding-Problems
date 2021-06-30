/*
Problem Statement: https://leetcode.com/problems/max-consecutive-ones/
Time: O(n)
Space: O(1)
Author: Mohammed Shoaib, github.com/Mohammed-Shoaib
*/

class Solution {
public:
	int findMaxConsecutiveOnes(vector<int>& nums) {
		int max_ones, ones;
		max_ones = ones = 0;
		
		for (int& x: nums) {
			if (x)
				ones++;
			else
				ones = 0;
			max_ones = max(ones, max_ones);
		}
		
		return max_ones;
	}
};