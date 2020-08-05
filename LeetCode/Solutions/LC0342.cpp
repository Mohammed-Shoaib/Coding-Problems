/*
Problem Statement: https://leetcode.com/problems/power-of-four/
Time: O(1)
Space: O(1)
Author: Mohammed Shoaib, github.com/Mohammed-Shoaib
*/

class Solution {
public:
	bool isPowerOfFour(int num) {
		return num > 0 && !(num & (num - 1)) && (__builtin_clz(num) & 1);
	}
};