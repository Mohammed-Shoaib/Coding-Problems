/*
Problem Statement: https://leetcode.com/problems/cheapest-flights-within-k-stops/
*/

class Solution {
public:
	int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
		vector<vector<pair<int, int>>> adj(n);
		priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> pq;

		// initialize
		pq.push({0, src, 0});

		// construct adjacency list
		for (auto& f: flights)
			adj[f[0]].emplace_back(f[1], f[2]);

		// djikstra's algorithm
		while (!pq.empty()) {
			int cost, stops;
			tie(cost, src, stops) = pq.top();
			pq.pop();
			if (src == dst)
				return cost;
			if (stops == K + 1)
				continue;
			for (auto& [u, w]: adj[src])
				pq.push({cost + w, u, stops + 1});
		}

		return -1;
	}
};