/*
Problem Statement: https://leetcode.com/problems/complement-of-base-10-integer/
*/

class Solution {
public:
    int bitwiseComplement(int N) {
		unsigned int mask = 1;
		while (mask < N)
			mask = (mask << 1) | 1;
		return N ^ mask;
    }
};