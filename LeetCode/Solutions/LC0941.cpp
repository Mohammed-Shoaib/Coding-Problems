/*
Problem Statement: https://leetcode.com/problems/valid-mountain-array/
Time: O(n)
Space: O(1)
Author: Mohammed Shoaib, github.com/Mohammed-Shoaib
*/

class Solution {
public:
	bool validMountainArray(vector<int>& A) {
		int i = 1, n = A.size();
		while (i < n && A[i - 1] < A[i])
			i++;
		if (i == 1 || i == n)
			return false;
		while (i < n && A[i - 1] > A[i])
			i++;
		return i == n;
	}
};