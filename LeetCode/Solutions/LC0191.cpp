/*
Problem Statement: https://leetcode.com/problems/number-of-1-bits/
Time: O(log n)
Space: O(1)
Author: Mohammed Shoaib, github.com/Mohammed-Shoaib
*/

class Solution {
public:
	int hammingWeight(uint32_t n) {
		// brian kernighan’s algorithm
		int cnt = 0;
		while (n) {
			cnt++;
			n &= n - 1;
		}
		return cnt;
	}
};