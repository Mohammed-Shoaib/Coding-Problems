/*
Problem Statement: https://leetcode.com/problems/course-schedule/
*/

class Solution {
public:
	bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
		bool is_cycle = false;
		vector<int> visited(numCourses);
		vector<vector<int>> adj(numCourses);
		
		// helper function
		function<void(int)> dfs = [&](int s) {
			visited[s] = 1;
			for (int& u: adj[s]) {
				if (!visited[u])
					dfs(u);
				else if (visited[u] == 1)
					is_cycle = true;
			}
			visited[s] = 2;
		};
		
		// construct adjacency list
		for (auto& edge: prerequisites)
			adj[edge[1]].push_back(edge[0]);
		
		for (int i = 0; i < numCourses; i++)
			if (!visited[i])
				dfs(i);
		
		return !is_cycle;
	}
};