/*
Problem Statement: https://leetcode.com/problems/sum-of-two-integers/
Time: O(1)
Space: O(1)
Author: Mohammed Shoaib, github.com/Mohammed-Shoaib
*/

class Solution {
public:
	int getSum(int a, int b) {
		while (b) {
			uint32_t c = a & b;
			a ^= b;
			b = c << 1;
		}
		return a;
	}
};