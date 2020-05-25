/*
Problem Statement: https://leetcode.com/problems/interval-list-intersections/
*/

class Solution {
public:
	vector<vector<int>> intervalIntersection(vector<vector<int>>& A, vector<vector<int>>& B) {
		int i, j, l, r;
		i = j = 0;
		vector<vector<int>> res;
		
		while (i < A.size() && j < B.size()) {
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