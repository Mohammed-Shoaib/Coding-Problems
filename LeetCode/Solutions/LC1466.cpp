/*
Problem Statement: https://leetcode.com/problems/reorder-routes-to-make-all-paths-lead-to-the-city-zero/
*/

class Solution {
public:
	int minReorder(int n, vector<vector<int>>& connections) {
		int changes = 0;
		vector<bool> visited(n);
		vector<vector<pair<int, int>>> adj(n);
		
		// helper function
		function<void(int)> dfs = [&](int s) {
			visited[s] = true;
			for (auto& [u, v]: adj[s])
				if (!visited[u]) {
					dfs(u);
					changes += v;
				}
		};

		// construct adjacency list
		for (auto& e: connections) {
			adj[e[0]].push_back({e[1], 1});
			adj[e[1]].push_back({e[0], 0});
		}
		dfs(0);

		return changes;
	}
};