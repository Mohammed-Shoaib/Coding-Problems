/*
Problem Statement: https://leetcode.com/problems/maximum-product-of-two-elements-in-an-array/
*/

class Solution {
public:
	int maxProduct(vector<int>& nums) {
		int m1, m2;
		m1 = m2 = 0;
		for (int& num: nums) {
			if (m1 < num)
				m2 = exchange(m1, num);
			else
				m2 = max(num, m2);
		}
		return (m1 - 1) * (m2 - 1);
	}
};