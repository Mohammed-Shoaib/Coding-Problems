/*
Problem Statement: https://leetcode.com/problems/smallest-string-with-swaps/
Time: O(m + n • log n)
Space: O(m + n)
Author: Mohammed Shoaib, github.com/Mohammed-Shoaib
*/

class Solution {
public:
	string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
		int n = s.length(), m = pairs.size();
		vector<int> component;
		vector<bool> visited(n);
		vector<vector<int>> adj(n);
		
		// helper function
		function<void(int)> dfs = [&](int s) {
			visited[s] = true;
			component.push_back(s);
			for (auto u: adj[s])
				if(!visited[u])
					dfs(u);
		};
		
		// create adjacency list
		for (int i = 0; i < pairs.size(); i++) {
			adj[pairs[i][0]].push_back(pairs[i][1]);
			adj[pairs[i][1]].push_back(pairs[i][0]);
		}
		
		// get all the components and sort them
		for (int i = 0; i < n; i++) {
			if (visited[i])
				continue;
			
			string substr;
			component.clear();
			dfs(i);
			
			for (int i = 0; i < component.size(); i++)
				substr += s[component[i]];
			
			sort(substr.begin(), substr.end());
			sort(component.begin(), component.end());
			
			for (int i = 0; i < component.size(); i++)
				s[component[i]] = substr[i];
		}
		
		return s;
	}
};