/*
Problem Statement: https://leetcode.com/problems/k-closest-points-to-origin/
Time: O(n²), average O(n)
Space: O(n)
Author: Mohammed Shoaib, github.com/Mohammed-Shoaib
*/

class Solution {
public:
	vector<vector<int>> kClosest(vector<vector<int>> points, int K) {
		int mid, low = 0, high = points.size() - 1;
		
		// quickselect algorithm
		while ((mid = partition(low, high, points)) != K - 1) {
			if (mid < K - 1)
				low = mid + 1;
			else
				high = mid - 1;
		}
		points.resize(K);
		
		return points;
	}
	
	int partition(int i, int j, vector<vector<int>>& points) {
		int k, pivot;
		k = i;
		pivot = distance(points[j]);
		while (i < j) {
			if (distance(points[i]) < pivot)
				swap(points[k++], points[i]);
			i++;
		}
		swap(points[k], points[j]);
		return k;
	}
	
	double distance(vector<int>& p) {
		return p[0] * p[0] + p[1] * p[1];
	}
};