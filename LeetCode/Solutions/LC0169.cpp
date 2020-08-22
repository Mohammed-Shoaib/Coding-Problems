/*
Problem Statement: https://leetcode.com/problems/majority-element/
Time: O(n)
Space: O(1)
Author: Mohammed Shoaib, github.com/Mohammed-Shoaib
*/

class Solution {
public:
	int majorityElement(vector<int>& nums) {
		int m, counter = 0;
		for (auto num: nums) {
			if (!counter)
				m = num;
			counter += (m == num) ? 1 : -1;
		}
		return m;
	}
};