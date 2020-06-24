/*
Problem Statement: https://leetcode.com/problems/single-number-ii/
*/

class Solution {
public:
	int singleNumber(vector<int>& nums) {
		int x = 0;
		for (int i = 0; i < 32; i++) {
			int b = 0;
			for (int& num: nums)
				b += (num >> i) & 1;
			b %= 3;
			x |= b << i;
		}
		return x;
	}
};