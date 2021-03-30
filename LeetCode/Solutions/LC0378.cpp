/*
Problem Statement: https://leetcode.com/problems/kth-smallest-element-in-a-sorted-matrix/
Time: O(m • log n)
Space: O(1)
Author: Mohammed Shoaib, github.com/Mohammed-Shoaib
*/

class Solution {
public:
	int kthSmallest(vector<vector<int>>& matrix, int k) {
		int m, n, low, high;
		m = matrix.size();
		n = matrix[0].size();
		low = matrix[0][0];
		high = matrix[m - 1][n - 1];
		
		// helper function
		auto count = [&](int x) {
			int cnt = 0;
			for (int i = 0; i < m; i++)
				cnt += distance(matrix[i].begin(), upper_bound(matrix[i].begin(), matrix[i].end(), x));
			return cnt;
		};
		
		// binary search
		while (low < high) {
			int mid = low + (high - low) / 2;
			if (count(mid) < k)
				low = mid + 1;
			else
				high = mid;
		}
		
		return low;
	}
};