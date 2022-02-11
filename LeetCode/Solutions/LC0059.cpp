/*
Problem Statement: https://leetcode.com/problems/spiral-matrix-ii/
Time: O(n²)
Space: O(n²)
Author: Mohammed Shoaib, github.com/Mohammed-Shoaib
*/

class Solution {
public:
	vector<vector<int>> generateMatrix(int n) {
		int x, y, dir;
		x = y = dir = 0;
		vector<vector<int>> matrix(n, vector<int>(n));
		
		// traverse directions easily
		vector<int> xdir = {0, 1, 0, -1};
		vector<int> ydir = {1, 0, -1, 0};
		
		// helper function
		function<bool(int, int)> valid = [&](int x, int y) {
			return x >= 0 && x < n
				&& y >= 0 && y < n
				&& matrix[x][y] == 0;
		};
		
		for (int k = 1; k <= n * n; k++) {
			matrix[x][y] = k;
			if (!valid(x + xdir[dir], y + ydir[dir]))
				dir = (dir + 1) % xdir.size();
			x += xdir[dir];
			y += ydir[dir];
		}
		
		return matrix;
	}
};