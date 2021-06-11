/*
Problem Statement: https://leetcode.com/problems/critical-connections-in-a-network/
Time: O(V + E)
Space: O(V + E)
Author: Mohammed Shoaib, github.com/Mohammed-Shoaib
*/

class Solution {
public:
	vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
		int id = 0;
		vector<bool> visited(n);
		vector<int> ids(n, -1), low(n, -1);
		vector<vector<int>> bridges, adj(n);
		
		// helper function
		function<void(int, int)> dfs = [&](int s, int par) {
			visited[s] = true;
			ids[s] = low[s] = id++;
			
			for (int& u: adj[s]) {
				if (u == par)
					continue;
				else if (visited[u])
					low[s] = min(ids[u], low[s]);
				else {
					dfs(u, s);
					low[s] = min(low[u], low[s]);
					if (ids[s] < low[u])
						bridges.push_back({s, u});
				}
			}
		};
		
		// create adjacency list
		for (auto& e: connections) {
			adj[e[0]].push_back(e[1]);
			adj[e[1]].push_back(e[0]);
		}
		
		// go through all connected components
		for (int i = 0; i < n; i++)
			if (!visited[i])
				dfs(i, -1);
		
		return bridges;
	}
};