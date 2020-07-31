/*
Problem Statement: https://leetcode.com/problems/climbing-stairs/
Time: O(n)
Space: O(1)
Author: Mohammed Shoaib, github.com/Mohammed-Shoaib
*/

class Solution {
public:
	int climbStairs(int n) {
		int f0 = 0, f1 = 1;
		while (n--)
			f0 = exchange(f1, f0 + f1);
		return f1;
	}
};