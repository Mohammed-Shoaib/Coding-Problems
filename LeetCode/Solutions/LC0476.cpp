/*
Problem Statement: https://leetcode.com/problems/number-complement/
*/

class Solution {
public:
	int findComplement(int num) {
		int mask = num;			// 1XXXXXXX XXXXXXXX XXXXXXXX XXXXXXXX
		mask |= (mask >> 1);	// 11XXXXXX XXXXXXXX XXXXXXXX XXXXXXXX
		mask |= (mask >> 2);	// 1111XXXX XXXXXXXX XXXXXXXX XXXXXXXX
		mask |= (mask >> 4);	// 11111111 XXXXXXXX XXXXXXXX XXXXXXXX
		mask |= (mask >> 8);	// 11111111 11111111 XXXXXXXX XXXXXXXX
		mask |= (mask >> 16);	// 11111111 11111111 11111111 11111111
		return num ^ mask;
	}
};