/*
Problem Statement: https://leetcode.com/problems/find-kth-bit-in-nth-binary-string/
Time: O(min(n, log k))
Space: O(1)
Author: Mohammed Shoaib, github.com/Mohammed-Shoaib
*/

class Solution {
public:
	char findKthBit(int n, int k) {
		int mid = 1 << (n - 1);
		if (n == 1)
			return '0';
		else if (mid == k)
			return '1';
		else if (mid > k)
			return findKthBit(n - 1, k);
		else
			return findKthBit(n - 1, 2 * mid - k) == '0' ? '1' : '0';
	}
};