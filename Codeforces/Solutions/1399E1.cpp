// Problem Code: 1399E1

#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <functional>

using namespace std;

int weights_division(int n, long long S, vector<vector<pair<int, int>>>& adj) {
	int moves = 0;
	long long cost = 0;
	vector<int> leaves(n);
	vector<long long> weight(n);
	priority_queue<pair<long long, int>> pq;
	
	// helper functions
	auto get_weight = [&](int s) {
		return ((weight[s] + 1) / 2) * leaves[s];
	};

	function<int(int, int)> dfs = [&](int s, int par) {
		leaves[s] = (s && adj[s].size() == 1);
		for (auto& [u, w]: adj[s])
			if (u != par) {
				dfs(u, s);
				weight[u] = w;
				leaves[s] += leaves[u];
				cost += weight[u] * leaves[u];
				pq.push({get_weight(u), u});
			}
		return leaves[s];
	};
	dfs(0, -1);

	while (cost > S) {
		moves++;
		cost -= pq.top().first;
		int s = pq.top().second;
		pq.pop();
		weight[s] /= 2;
		pq.push({get_weight(s), s});
	}

	return moves;
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n;
		long long S;
		cin >> n >> S;
		vector<vector<pair<int, int>>> adj(n);
		for (int i = 0; i < n - 1; i++) {
			int v, u, w;
			cin >> v >> u >> w;
			--v, --u;
			adj[v].emplace_back(u, w);
			adj[u].emplace_back(v, w);
		}
		cout << weights_division(n, S, adj) << endl;
	}
	return 0;
}