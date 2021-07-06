/*
Problem Statement: https://leetcode.com/problems/swim-in-rising-water/
Time: O(m • n • log (m • n))
Space: O(m • n)
Author: Mohammed Shoaib, github.com/Mohammed-Shoaib
*/

class Solution {
public:
	int swimInWater(vector<vector<int>>& grid) {
		int max_w = 0, m = grid.size(), n = grid[0].size();
		vector<vector<bool>> visited(m, vector<bool>(n));
		priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
		
		// traverse directions easily
		vector<int> xdir = {-1, 0, 1, 0};
		vector<int> ydir = {0, -1, 0, 1};
		
		// helper function
		auto valid = [&](int x, int y) {
			return x >= 0 && x < m && y >= 0 && y < n && !visited[x][y];
		};
		
		// initialization
		pq.push({0, 0});
		
		// djikstra's shortest path
		while (!pq.empty()) {
			int w, idx;
			tie(w, idx) = pq.top();
			pq.pop();
			max_w = max(w, max_w);
			
			// reached the target
			if (idx == m * n - 1)
				return max_w;
			
			int x = idx / n, y = idx % n;
			visited[x][y] = true;
			
			// traverse the neighbors
			for (int k = 0; k < xdir.size(); k++) {
				int new_x = x + xdir[k], new_y = y + ydir[k];
				if (valid(new_x, new_y))
					pq.push({max(grid[x][y], grid[new_x][new_y]), n * new_x + new_y});
			}
		}
		
		return -1;
	}
};
