/*
Problem Statement: https://leetcode.com/problems/product-of-array-except-self/
Time: O(n)
Space: O(n)
Author: Mohammed Shoaib, github.com/Mohammed-Shoaib
*/

class Solution {
public:
	vector<int> productExceptSelf(vector<int>& nums) {
		int suffix, n = nums.size();
		vector<int> output(n);
		output[0] = suffix = 1;
		
		// compute prefix product
		for (int i = 0; i < n - 1; i++)
			output[i + 1] = output[i] * nums[i];
		
		// compute suffix product and update output
		for (int i = n - 1; i >= 0; i--) {
			output[i] *= suffix;
			suffix *= nums[i];
		}
		
		return output;
	}
};