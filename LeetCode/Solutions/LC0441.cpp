/*
Problem Statement: https://leetcode.com/problems/arranging-coins/
Time: O(1)
Space: O(1)
Author: Mohammed Shoaib, github.com/Mohammed-Shoaib
*/

class Solution {
public:
	int arrangeCoins(long long n) {
		return sqrt(2 * n + 0.25) - 0.5;
	}
};