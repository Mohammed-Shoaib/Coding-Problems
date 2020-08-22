/*
Problem Statement: https://leetcode.com/problems/bitwise-and-of-numbers-range/
Time: O(log n)
Space: O(1)
Author: Mohammed Shoaib, github.com/Mohammed-Shoaib
*/

class Solution {
public:
	int rangeBitwiseAnd(int m, int n) {
		while (m < n)
			n -= n & -n;	// remove last set bit of n
		return n;
	}
};