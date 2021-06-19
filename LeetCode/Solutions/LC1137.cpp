/*
Problem Statement: https://leetcode.com/problems/n-th-tribonacci-number/
Time: O(n)
Space: O(1)
Author: Mohammed Shoaib, github.com/Mohammed-Shoaib
*/

class Solution {
public:
	int tribonacci(int n) {
		vector<int> t(3);
		t[1] = t[2] = 1;
		
		// base case
		if (n == 0)
			return t[0];
		
		// simulate
		n = max(0, n - 2);
		while (n--)
			t[2] = exchange(t[0], t[1]) + exchange(t[1], t[2]) + t[2];
		
		return t[2];
	}
};