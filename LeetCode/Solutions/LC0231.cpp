/*
Problem Statement: https://leetcode.com/problems/power-of-two/
Time: O(1)
Space: O(1)
Author: Mohammed Shoaib, github.com/Mohammed-Shoaib
*/

class Solution {
public:
	bool isPowerOfTwo(int n) {
		return n > 0 && !(n & (n - 1));
	}
};