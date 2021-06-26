/*
Problem Statement: https://leetcode.com/problems/sign-of-the-product-of-an-array/
Time: O(n)
Space: O(1)
Author: Mohammed Shoaib, github.com/Mohammed-Shoaib
*/

class Solution {
public:
	int arraySign(vector<int>& nums) {
		int sign = 1;
		for (int& x: nums) {
			if (x == 0)
				return 0;
			else if (x < 0)
				sign *= -1;
		}
		return sign;
	}
};