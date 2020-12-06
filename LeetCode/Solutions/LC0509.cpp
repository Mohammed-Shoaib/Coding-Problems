/*
Problem Statement: https://leetcode.com/problems/fibonacci-number/
Time: O(n)
Space: O(1)
Author: Mohammed Shoaib, github.com/Mohammed-Shoaib
*/

class Solution {
public:
	int fib(int N) {
		int f0 = 0, f1 = 1;
		if (N == 0)
			return f0;
		while (--N)
			f1 += exchange(f0, f1);
		return f1;
	}
};