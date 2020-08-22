/*
Problem Statement: https://leetcode.com/problems/hamming-distance/
Time: O(1)
Space: O(1)
Author: Mohammed Shoaib, github.com/Mohammed-Shoaib
*/

class Solution {
public:
	int hammingDistance(int x, int y) {
		return count(x ^ y);
	}
	
	int count(int b) {
		// brian kernighan’s algorithm
		int cnt = 0;
		while (b) {
			b &= b - 1;
			cnt++;
		}
		return cnt;
	}
};