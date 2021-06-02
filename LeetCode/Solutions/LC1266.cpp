/*
Problem Statement: https://leetcode.com/problems/minimum-time-visiting-all-points/
Time: O(n)
Space: O(1)
Author: Mohammed Shoaib, github.com/Mohammed-Shoaib
*/

class Solution {
public:
	int minTimeToVisitAllPoints(vector<vector<int>>& points) {
		int t = 0, n = points.size();
		for (int i = 1; i < n; i++)
			t += dist(points[i - 1], points[i]);
		return t;
	}
	
	int dist(vector<int>& p1, vector<int>& p2) {
		int dx, dy;
		dx = abs(p1[0] - p2[0]);
		dy = abs(p1[1] - p2[1]);
		return max(dx, dy);
	}
};