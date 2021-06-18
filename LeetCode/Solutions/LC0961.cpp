/*
Problem Statement: https://leetcode.com/problems/n-repeated-element-in-size-2n-array/
Time: O(n)
Space: O(1)
Author: Mohammed Shoaib, github.com/Mohammed-Shoaib
*/

class Solution {
public:
	int repeatedNTimes(vector<int>& A) {
		int n = A.size();
		for (int j = 1; j <= 3; j++)
			for (int i = 0; i < n - j; i++)
				if (A[i] == A[i + j])
					return A[i];
		return -1;
	}
};