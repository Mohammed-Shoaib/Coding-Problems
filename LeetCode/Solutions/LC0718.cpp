/*
Problem Statement: https://leetcode.com/problems/maximum-length-of-repeated-subarray/
*/

class Solution {
public:
	int findLength(vector<int> &A, vector<int> &B) {
		int n, m, length;
		n = A.size();
		m = B.size();
		length = 0;
		vector<int> prev(m), curr(m);

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++)
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