/*
Problem Statement: https://leetcode.com/problems/queries-on-number-of-points-inside-a-circle/
Time: O(n • log n + n • q)
Space: O(n • q)
Author: Mohammed Shoaib, github.com/Mohammed-Shoaib
*/

class Solution {
private:
	int euclidean_distance(int x1, int y1, int x2, int y2) {
		int x = x2 - x1, y = y2 - y1;
		return x * x + y * y;
	}

public:
	vector<int> countPoints(vector<vector<int>> points, vector<vector<int>>& queries) {
		int n = points.size(), q = queries.size();
		vector<int> res(q);
		sort(points.begin(), points.end());
		
		for (int i = 0; i < q; i++) {
			int rr, pos;
			vector<int>& q = queries[i];
			rr = q[2] * q[2];
			pos = distance(points.begin(), lower_bound(points.begin(), points.end(), q[0] - q[2], [](auto& p, int x) {
				return p[0] < x;
			}));
			
			for (int j = pos; j < n && points[j][0] <= q[0] + q[2]; j++) {
				vector<int>& p = points[j];
				res[i] += (euclidean_distance(p[0], p[1], q[0], q[1]) <= rr);
			}
		}
		
		return res;
	}
};