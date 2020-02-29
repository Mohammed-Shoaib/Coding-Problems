/*
Problem Statement: https://leetcode.com/problems/smallest-string-with-swaps/
*/

class Solution {
public:
    vector<bool> visited;
    vector< vector<int> > adj;

    string smallestStringWithSwaps(string s, vector< vector<int> > &pairs) {
        int n = s.length();
        visited = vector<bool>(n);
        adj = vector< vector<int> >(n);
        
        // Create adjacency list
        for (int i = 0; i < pairs.size(); i++) {
        	adj[pairs[i][0]].push_back(pairs[i][1]);
        	adj[pairs[i][1]].push_back(pairs[i][0]);
        }

        // Get all components and sort them
        for (int i = 0; i < n; i++) {
            if (visited[i])
                continue;

            string substr;
            vector<int> component;
            DFS(i, component);

            for (int i = 0; i < component.size(); i++)
                substr += s[component[i]];

            sort(substr.begin(), substr.end());
            sort(component.begin(), component.end());

            for (int i = 0; i < component.size(); i++)
                s[component[i]] = substr[i];
        }
        
        return s;
    }

    void DFS(int s, vector<int> &component) {
    	visited[s] = true;
        component.push_back(s);
        for (auto u: adj[s])
            if(!visited[u])
                DFS(u, component);
    }
};