/*
Problem Statement: https://leetcode.com/problems/maximum-length-of-subarray-with-positive-product/
Time: O(n)
Space: O(1)
Author: Mohammed Shoaib, github.com/Mohammed-Shoaib
*/

class Solution {
public:
	int getMaxLen(vector<int>& nums) {
		int len, pos, neg;
		len = pos = neg = 0;
		
		for (int& x: nums) {
			pos++;
			if (neg)
				neg++;
			if (x == 0)
				pos = neg = 0;
			else if (x < 0)
				swap(pos, neg);
			len = max(pos, len);
		}
		
		return len;
	}
};