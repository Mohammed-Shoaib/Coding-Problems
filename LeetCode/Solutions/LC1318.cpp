/*
Problem Statement: https://leetcode.com/problems/minimum-flips-to-make-a-or-b-equal-to-c/
Time: O(32)
Space: O(1)
Author: Mohammed Shoaib, github.com/Mohammed-Shoaib
*/

class Solution {
public:
	int minFlips(int a, int b, int c) {
		int flips = 0;
		for (int i = 0, m = 1; i < 31; i++, m <<= 1) {
			if (~c & a & b & m)
				flips++;
			flips += ((c ^ (a | b)) & m) >> i;
		}
		return flips;
	}
};