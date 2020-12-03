/*
Problem Statement: https://leetcode.com/problems/power-of-three/
Time: O(1)
Space: O(1)
Author: Mohammed Shoaib, github.com/Mohammed-Shoaib
*/

class Solution {
public:
	bool isPowerOfThree(long long n) {
		return n > 0 && fmod(log10(n) / log10(3), 1) == 0;
		// non-intuitive: return n > 0 && 1162261467 % n == 0;
	}
};