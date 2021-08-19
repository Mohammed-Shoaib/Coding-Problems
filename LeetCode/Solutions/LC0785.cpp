/*
Problem Statement: https://leetcode.com/problems/is-graph-bipartite/
Time: O(V + E)
Space: O(V)
Author: Mohammed Shoaib, github.com/Mohammed-Shoaib
*/

class Solution {
public:
	bool isBipartite(vector<vector<int>>& graph) {
		int n = graph.size();
		vector<int> color(n);
		
		for (int i = 0; i < n; i++) {
			if (color[i])
				continue;
			
			// initialization
			queue<int> q;
			q.push(i);
			color[i] = 1;
			
			// BFS
			while (!q.empty()) {
				int src = q.front();
				q.pop();
				for (int& u: graph[src]) {
					if (!color[u]) {
						q.push(u);
						color[u] = -color[src];
					}
					else if (color[u] == color[src])
						return false;
				}
			}
		}
		
		return true;
	}
};