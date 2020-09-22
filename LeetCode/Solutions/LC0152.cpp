/*
Problem Statement: https://leetcode.com/problems/maximum-product-subarray/
Time: O(n)
Space: O(1)
Author: Mohammed Shoaib, github.com/Mohammed-Shoaib
*/

class Solution {
public:
	int maxProduct(vector<int>& nums) {
		int max_prod, min_end, max_end;
		min_end = max_end = 1;
		max_prod = numeric_limits<int>::min();
		
		for (int& x: nums) {
			int min_prev = min_end;
			min_end = min({max_end * x, min_prev * x, x});
			max_end = max({max_end * x, min_prev * x, x});
			max_prod = max(max_end, max_prod);
		}
		
		return max_prod;
	}
};