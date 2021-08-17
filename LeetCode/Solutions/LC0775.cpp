/*
Problem Statement: https://leetcode.com/problems/global-and-local-inversions/
Time: O(n)
Space: O(1)
Author: Mohammed Shoaib, github.com/Mohammed-Shoaib
*/

class Solution {
public:
	bool isIdealPermutation(vector<int>& A) {
		int n = A.size();
		
		for (int i = 0; i < n; i++)
			if (abs(A[i] - i) > 1)
				return false;
		
		return true;
	}
};