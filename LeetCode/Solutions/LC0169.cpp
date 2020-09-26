/*
Problem Statement: https://leetcode.com/problems/majority-element/
Time: O(n)
Space: O(1)
Author: Mohammed Shoaib, github.com/Mohammed-Shoaib
*/

class Solution {
public:
	int majorityElement(vector<int>& nums) {
		// Boyer–Moore majority vote
		int m, cnt = 0;
		for (int& x: nums) {
			if (cnt == 0)
				m = x;
			cnt += 2 * (m == x) - 1;
		}
		return m;
	}
};