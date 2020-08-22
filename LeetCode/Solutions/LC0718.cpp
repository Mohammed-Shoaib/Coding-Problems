/*
Problem Statement: https://leetcode.com/problems/maximum-length-of-repeated-subarray/
Time: O(m • n)
Space: O(n)
Author: Mohammed Shoaib, github.com/Mohammed-Shoaib
*/

class Solution {
public:
	int findLength(vector<int>& A, vector<int>& B) {
		int m, n, length;
		m = A.size();
		n = B.size();
		length = 0;
		vector<int> prev(n), curr(n);
		
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++)
				if (A[i] == B[j]) {
					if (i == 0 || j == 0)
						curr[j] = 1;
					else
						curr[j] = prev[j - 1] + 1;
					length = max(curr[j], length);
				}
			prev = curr;
			fill(curr.begin(), curr.end(), 0);
		}
		
		return length;
	}
};