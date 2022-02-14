/*
Problem Statement: https://leetcode.com/problems/spiral-matrix-iii/
Time: O(rows • cols)
Space: O(rows • cols)
Author: Mohammed Shoaib, github.com/Mohammed-Shoaib
*/

class Solution {
public:
	vector<vector<int>> spiralMatrixIII(int rows, int cols, int x, int y) {
		int dir = 0;
		vector<vector<int>> order;
		
		// traverse directions easily
		vector<int> xdir = {0, 1, 0, -1};
		vector<int> ydir = {1, 0, -1, 0};
		
		// helper function
		function<bool(int, int)> valid = [&](int x, int y) {
			return x >= 0 && x < rows && y >= 0 && y < cols;
		};
		
		// initialization
		order.push_back({x, y});
		
		// traverse the matrix in spiral order
		for (int k = 0; order.size() < rows * cols; k++) {
			for (int steps = 0; steps < k / 2 + 1; steps++) {
				x += xdir[dir];
				y += ydir[dir];
				if (valid(x, y))
					order.push_back({x, y});
			}
			dir = (dir + 1) % xdir.size();
		}
		
		return order;
	}
};