/*
Problem Statement: https://leetcode.com/problems/matrix-cells-in-distance-order/
Time: O(R • C)
Space: O(R • C)
Author: Mohammed Shoaib, github.com/Mohammed-Shoaib
*/

class Solution {
public:
	vector<vector<int>> allCellsDistOrder(int R, int C, int r0, int c0) {
		queue<vector<int>> q;
		vector<vector<int>> res;
		vector<vector<bool>> visited(R, vector<bool>(C));
		
		// traverse directions easily
		vector<int> xdir = {-1, 0, 1, 0};
		vector<int> ydir = {0, -1, 0, 1};
		
		// initialization
		q.push({r0, c0});
		visited[r0][c0] = true;
		
		// BFS
		while (!q.empty()) {
			vector<int> pos = q.front();
			q.pop();
			res.push_back(pos);
			for (int i = 0; i < xdir.size(); i++) {
				int x = pos[0] + xdir[i], y = pos[1] + ydir[i];
				if (x >= 0 && x < R && y >= 0 && y < C && !visited[x][y]) {
					q.push({x, y});
					visited[x][y] = true;
				}
			}
		}
		
		return res;
	}
};