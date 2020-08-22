/*
Problem Statement: https://leetcode.com/problems/flood-fill/
Time: O(m • n)
Space: O(m • n)
Author: Mohammed Shoaib, github.com/Mohammed-Shoaib
*/

class Solution {
public:
	vector<vector<int>> floodFill(vector<vector<int>> image, int sr, int sc, int newColor) {
		int m, n, color;
		queue<pair<int, int>> q;
		
		// initialization
		m = image.size();
		n = image[0].size();
		color = exchange(image[sr][sc], newColor);
		vector<int> x_dir = {-1, 0, 1, 0};
		vector<int> y_dir = {0, -1, 0, 1};
		if (color != newColor)
			q.push({sr, sc});
		
		// helper function
		auto valid = [&](int x, int y) -> bool {
			return (x >= 0 && x < m) && (y >= 0 && y < n);
		};
		
		// flood-fill algorithm
		while (!q.empty()) {
			tie(sr, sc) = q.front();
			q.pop();
			for (int i = 0; i < x_dir.size(); i++) {
				int new_x, new_y;
				new_x = sr + x_dir[i];
				new_y = sc + y_dir[i];
				if (valid(new_x, new_y) && image[new_x][new_y] == color) {
					image[new_x][new_y] = newColor;
					q.push({new_x, new_y});
				}
			}
		}
		
		return image;
	}
};