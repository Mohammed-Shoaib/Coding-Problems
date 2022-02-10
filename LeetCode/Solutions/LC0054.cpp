/*
Problem Statement: https://leetcode.com/problems/spiral-matrix/
Time: O(m • n)
Space: O(m • n)
Author: Mohammed Shoaib, github.com/Mohammed-Shoaib
*/

class Solution {
public:
	vector<int> spiralOrder(vector<vector<int>>& matrix) {
		int m = matrix.size(), n = matrix[0].size();
		int dir = 0, x = 0, y = -1;
		vector<int> order, steps = {n, m - 1};
		
		// traverse directions easily
		vector<int> xdir = {0, 1, 0, -1};
		vector<int> ydir = {1, 0, -1, 0};
		
		while (steps[dir % 2]) {
			for (int k = 0; k < steps[dir % 2]; k++) {
				x += xdir[dir];
				y += ydir[dir];
				order.push_back(matrix[x][y]);
			}
			steps[dir % 2]--;
			dir = (dir + 1) % 4;
		}
		
		return order;
	}
};