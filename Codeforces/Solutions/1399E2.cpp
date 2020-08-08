// Problem Code: 1399E2

#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <limits>
#include <functional>

using namespace std;

int weights_division(int n, long long S, vector<vector<vector<int>>>& adj) {
	int min_coins = numeric_limits<int>::max();
	vector<int> coins(n), leaves(n);
	vector<long long> weight(n), costs[2];

	// helper functions
	auto get_weight = [&](int s) {
		return ((weight[s] + 1) / 2) * leaves[s];
	};

	function<int(int, int)> dfs = [&](int s, int par) {
		leaves[s] = (s && adj[s].size() == 1);
		for (auto& edge: adj[s]) {
			int u = edge[0];
			if (u != par) {
				dfs(u, s);
				leaves[s] += leaves[u];
				weight[u] = edge[1];
				coins[u] = edge[2];
			}
		}
		return leaves[s];
	};

	auto get_cost = [&](int coin) {
		long long cost = 0;
		priority_queue<pair<long long, int>> pq;

		for (int i = 0; i < n; i++)
			if (coins[i] == coin) {
				cost += weight[i] * leaves[i];
				pq.push({get_weight(i), i});
			}
		costs[coin == 2].push_back(cost);

		while (cost > 0) {
			cost -= pq.top().first;
			int s = pq.top().second;
			pq.pop();
			weight[s] /= 2;
			pq.push({get_weight(s), s});
			costs[coin == 2].push_back(cost);
		}
	};

	dfs(0, -1);
	get_cost(1);
	get_cost(2);

	for (int c1 = 0; c1 < costs[0].size(); c1++) {
		auto it = lower_bound(costs[1].begin(), costs[1].end(), S - costs[0][c1], greater<long long>());
		if (it != costs[1].end()) {
			int c2 = distance(costs[1].begin(), it);
			min_coins = min(c1 + 2 * c2, min_coins);
		}
	}

	return min_coins;
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n;
		long long S;
		cin >> n >> S;
		vector<vector<vector<int>>> adj(n);
		for (int i = 0; i < n - 1; i++) {
			int v, u, w, c;
			cin >> v >> u >> w >> c;
			--v, --u;
			adj[v].push_back({u, w, c});
			adj[u].push_back({v, w, c});
		}
		cout << weights_division(n, S, adj) << endl;
	}
	return 0;
}