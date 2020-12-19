/*
Problem Statement: https://leetcode.com/problems/largest-triangle-area/
*/

class Solution {
public:
	double largestTriangleArea(vector< vector<int> >& points) {
		double max_area = 0;
		for (int i = 0; i < points.size() - 2; i++)
			for (int j = i + 1; j < points.size() - 1; j++)
				for (int k = j + 1; k < points.size(); k++)
					max_area = max(area(points[i], points[j], points[k]), max_area);
		return max_area;
	}

	double area(vector<int>& a, vector<int>& b, vector<int>& c) {
		return 0.5 * abs(a[0] * (b[1] - c[1]) + b[0] * (c[1] - a[1]) + c[0] * (a[1] - b[1]));
	}
};