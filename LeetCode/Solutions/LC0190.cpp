/*
Problem Statement: https://leetcode.com/problems/reverse-bits/
Time: O(1)
Space: O(1)
Author: Mohammed Shoaib, github.com/Mohammed-Shoaib
*/

class Solution {
public:
	uint32_t reverseBits(uint32_t n) {
		uint32_t b = 0;
		for (int i = 0; i < 32; i++) {
			b <<= 1;
			b |= n & 1;
			n >>= 1;
		}
		return b;
	}
};