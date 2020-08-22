/*
Problem Statement: https://leetcode.com/problems/all-paths-from-source-to-target/
Time: O(n • 2ⁿ)
Space: O(2ⁿ)
Author: Mohammed Shoaib, github.com/Mohammed-Shoaib
*/

class Solution {
public:
	vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
		int n = graph.size();
		vector<int> path;
		vector<vector<int>> paths;
		
		// helper function to backtrack
		function<void(int)> dfs = [&](int s) {
			path.push_back(s);
			if (s == n - 1)
				paths.push_back(path);
			for (int& u: graph[s])
				dfs(u);
			path.pop_back();
		};
		dfs(0);
		
		return paths;
	}
};