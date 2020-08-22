/*
Problem Statement: https://leetcode.com/problems/sort-array-by-parity/
Time: O(n)
Space: O(1)
Author: Mohammed Shoaib, github.com/Mohammed-Shoaib
*/

class Solution {
public:
	vector<int> sortArrayByParity(vector<int> A) {
		int i = 0, j = A.size() - 1;
		while (i < j) {
			if (A[i] & 1)
				swap(A[i], A[j--]);
			else
				i++;
		}
		return A;
	}
};