/*
Problem Statement: https://leetcode.com/problems/possible-bipartition/
*/

class Solution {
public:
	bool possibleBipartition(int N, vector<vector<int>>& dislikes) {
		bool is_bipartite = true;
		vector<int> color(N + 1);
		vector<bool> visited(N + 1);
		vector<vector<int>> adj(N + 1);

		// helper function
		function<void(int, int)> dfs = [&](int s, int col) {
			color[s] = col;
			visited[s] = true;
			for (int& u: adj[s]) {
				if (visited[u])
					is_bipartite &= color[u] != color[s];
				else
					dfs(u, (color[s] + 1) % 2);
			}
		};

		// construct adjacency list
		for (auto& edge: dislikes) {
			adj[edge[0]].push_back(edge[1]);
			adj[edge[1]].push_back(edge[0]);
		}
		
		for (int i = 1; i <= N; i++) 
			if (!visited[i])
				dfs(i, 0);

		return is_bipartite;
	}
};