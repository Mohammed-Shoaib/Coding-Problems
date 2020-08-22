/*
Problem Statement: https://leetcode.com/problems/valid-perfect-square/
Time: O(log n)
Space: O(1)
Author: Mohammed Shoaib, github.com/Mohammed-Shoaib
*/

class Solution {
public:
	bool isPerfectSquare(int num) {
		// newton's method
		long long x = num;
		while (x * x > num)
			x = (x + num / x) / 2;
		return (x * x == num);
	}
};