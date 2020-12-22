/*
Problem Statement: https://leetcode.com/problems/binary-gap/
Time: O(log n)
Space: O(1)
Author: Mohammed Shoaib, github.com/Mohammed-Shoaib
*/

class Solution {
public:
	int binaryGap(int n) {
		int gap = 0;
		
		for (int i = -1, j = 0; n; n >>= 1, j++)
			if (n & 1) {
				if (i != -1)
					gap = max(j - i, gap);
				i = j;
			}
		
		return gap;
	}
};