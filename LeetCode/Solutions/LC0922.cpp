/*
Problem Statement: https://leetcode.com/problems/sort-array-by-parity-ii/
Time: O(n)
Space: O(1)
Author: Mohammed Shoaib, github.com/Mohammed-Shoaib
*/

class Solution {
public:
	vector<int> sortArrayByParityII(vector<int> A) {
		int i = 0, n = A.size();
		vector<int> pos = {n - 2, n - 1};
		
		while (i < n) {
			int j = A[i] & 1;
			if ((i & 1) ^ j) {
				swap(A[i], A[pos[j]]);
				pos[j] -= 2;
			}
			else
				i++;
		}
		
		return A;
	}
};