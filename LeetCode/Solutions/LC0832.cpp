/*
Problem Statement: https://leetcode.com/problems/flipping-an-image/
Time: O(n • m)
Space: O(n • m)
Author: Mohammed Shoaib, github.com/Mohammed-Shoaib
*/

class Solution {
public:
	vector<vector<int>> flipAndInvertImage(vector<vector<int>> A) {
		int n, m;
		n = A.size();
		m = A[0].size();
		
		for (int i = 0; i < n; i++) {
			reverse(A[i].begin(), A[i].end());
			for (int j = 0; j < n; j++)
				A[i][j] ^= 1;
		}
		
		return A;
	}
};