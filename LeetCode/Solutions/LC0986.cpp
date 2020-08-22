/*
Problem Statement: https://leetcode.com/problems/interval-list-intersections/
Time: O(m + n)
Space: O(m + n)
Author: Mohammed Shoaib, github.com/Mohammed-Shoaib
*/

class Solution {
public:
	vector<vector<int>> intervalIntersection(vector<vector<int>>& A, vector<vector<int>>& B) {
		int i, j, m, n;
		i = j = 0;
		m = A.size();
		n = B.size();
		vector<vector<int>> res;
		
		while (i < m && j < n) {
			int l, r;
			l = max(A[i][0], B[j][0]);
			r = min(A[i][1], B[j][1]);
			if (l <= r)
				res.push_back({l, r});
			if (A[i][1] <= B[j][1])
				i++;
			else
				j++;
		}
		
		return res;
	}
};