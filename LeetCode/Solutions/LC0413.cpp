/*
Problem Statement: https://leetcode.com/problems/arithmetic-slices/
Time: O(n)
Space: O(1)
Author: Mohammed Shoaib, github.com/Mohammed-Shoaib
*/

class Solution {
public:
	int numberOfArithmeticSlices(vector<int>& A) {
		int slices = 0, n = A.size();
		
		for (int i = 2, j = 1; i < n; i++) {
			if (A[i] - A[i - 1] != A[j] - A[j - 1])
				j = i;
			slices += i - j;
		}
		
		return slices;
	}
};