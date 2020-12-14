/*
Problem Statement: https://leetcode.com/problems/trim-a-binary-search-tree/
Time: O(log n)
Space: O(1)
Author: Mohammed Shoaib, github.com/Mohammed-Shoaib
*/

class Solution {
public:
	bool hasAlternatingBits(int n) {
		bool prev = n & 1;
		while (n) {
			n >>= 1;
			if ((n & 1) == exchange(prev, n & 1))
				return false;
		}
		return true;
	}
};