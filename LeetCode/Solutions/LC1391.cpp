/*
Problem Statement: https://leetcode.com/problems/check-if-there-is-a-valid-path-in-a-grid/
*/

class Solution {
public:
	bool hasValidPath(vector<vector<int>>& grid) {
		int m, n;
		m = grid.size();
		n = grid[0].size();
		queue<pair<int, int>> q;
		vector<vector<int>> adj(4), move(7);
		pair<int, int> s, t = {m - 1, n - 1};
		vector<vector<bool>> visited(m, vector<bool>(n));
		
		// directions: up, down, left, right
		vector<int> x_dir = {-1, 1, 0, 0};
		vector<int> y_dir = {0, 0, -1, 1};

		adj[0] = {2, 3, 4};		// moving up    we can go to street 2, 3, 4
		adj[1] = {2, 5, 6};		// moving down  we can go to street 2, 5, 6
		adj[2] = {1, 4, 6};		// moving left  we can go to street 1, 4, 6
		adj[3] = {1, 3, 5};		// moving right we can go to street 1, 3, 5
		
		// populate the directions we can move from a street
		for (int i = 0; i < adj.size(); i++)
			for (int street: adj[i])
				move[street].push_back(i ^ 1);	// we are coming from the opposite direction
		
		// helper function
		auto process = [&](int u, int v, int street) {
			if (u >= 0 && u < m && v >= 0 && v < n && !visited[u][v] && grid[u][v] == street) {
				q.push({u, v});
				visited[u][v] = true;
			}
		};

		// standard BFS
		process(0, 0, grid[0][0]);
		while (!q.empty()) {
			int u, v, new_u, new_v;
			s = q.front();
			tie(u, v) = s;
			q.pop();
			
			if (s == t)
				return true;
			
			for (int i = 0; i < x_dir.size(); i++) {
				if (!count(move[grid[u][v]].begin(), move[grid[u][v]].end(), i))
					continue;
				new_u = u + x_dir[i];
				new_v = v + y_dir[i];
				for (int street: adj[i])
					process(new_u, new_v, street);
			}
		}

		return false;
	}
};