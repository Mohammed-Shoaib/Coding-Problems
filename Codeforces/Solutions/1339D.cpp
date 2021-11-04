// Problem Code: 1339D

#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <functional>

using namespace std;

pair<int, int> edge_weight(int n, vector<vector<int>>& adj) {
	bool dist[2] = {};
	vector<int> leaves(n + 1);

	// helper function
	function<void(int, int, int)> dfs = [&](int s, int p, int d) {
		if (adj[s].size() == 1) {
			dist[d] = true;
			leaves[adj[s][0]]++;
		}
		for (int u: adj[s])
			if (u != p)
				dfs(u, s, d ^ 1);
	};
	dfs(1, 0, 0);
	
	int mn, mx;
	mn = (dist[0] ^ dist[1]) ? 1 : 3;	// 3 if both odd & even path lengths exist
	mx = n - 1;
	for (int i = 1; i <= n; i++)
		mx -= max(0, leaves[i] - 1);	// subtract any multiple leaf nodes from the maximum

	return {mn, mx};
}

int main() {
	int n, a, b;
	cin >> n;
	vector<vector<int>> adj(n + 1);
	for (int i = 1; i < n; i++) {
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	pair<int, int> f = edge_weight(n, adj);
	cout << f.first << " " << f.second;
	return 0;
}