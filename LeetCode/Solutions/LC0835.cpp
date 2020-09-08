/*
Problem Statement: https://leetcode.com/problems/image-overlap/
Time: O(n⁴)
Space: O(n²)
Author: Mohammed Shoaib, github.com/Mohammed-Shoaib
*/

class Solution {
public:
	int largestOverlap(vector<vector<int>>& A, vector<vector<int>>& B) {
		int max_cnt = 0, n = A.size();
		vector<pair<int, int>> a, b;
		vector<vector<int>> cnt(2 * n, vector<int>(2 * n));
		
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++) {
				if (A[i][j])
					a.emplace_back(i, j);
				if (B[i][j])
					b.emplace_back(i, j);
			}
		
		for (auto& [ax, ay]: a)
			for (auto& [bx, by]: b)
				max_cnt = max(++cnt[n + ax - bx][n + ay - by], max_cnt);
		
		return max_cnt;
	}
};