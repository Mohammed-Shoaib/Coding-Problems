/*
Problem Statement: https://leetcode.com/problems/course-schedule-ii/
Time: O(V + E)
Space: O(V + E)
Author: Mohammed Shoaib, github.com/Mohammed-Shoaib
*/

class Solution {
public:
	vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
		bool has_cycle = false;
		vector<int> order;
		vector<int> visited(numCourses);
		vector<vector<int>> adj(numCourses);
		
		// helper function to perform topological sort
		function<void(int)> dfs = [&](int s) {
			visited[s] = 1;
			for (int& u: adj[s]) {
				if (!visited[u])
					dfs(u);
				else if (visited[u] == 1)
					has_cycle = true;
			}
			visited[s] = 2;
			order.push_back(s);
		};
		
		// construct adjacency list
		for (auto& edge: prerequisites)
			adj[edge[1]].push_back(edge[0]);
		
		for (int i = 0; i < numCourses; i++)
			if (!visited[i])
				dfs(i);
		reverse(order.begin(), order.end());
		
		if (has_cycle)
			order.clear();
		
		return order;
	}
};