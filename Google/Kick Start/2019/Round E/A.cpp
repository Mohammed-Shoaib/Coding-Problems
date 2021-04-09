#include <iostream>
#include <vector>
#include <functional>

using namespace std;

int cherries_mesh(int N, int M, vector<vector<int>>& adj) {
	int cost = N - 2;
	vector<bool> visited(N + 1);
	
	function<void(int)> dfs = [&](int s) {
		visited[s] = true;
		for (int u: adj[s])
			if (!visited[u])
				dfs(u);
	};
	
	for (int i = 1; i <= N; i++)
		if (!visited[i]) {
			cost++;
			dfs(i);
		}
	
	return cost;
}

int main() {
	int T;
	cin >> T;
	for (int x = 1; x <= T; x++) {
		int N, M;
		cin >> N >> M;
		vector<vector<int>> adj(N + 1);
		for (int i = 0; i < M; i++) {
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		cout << "Case #" << x << ": " << cherries_mesh(N, M, adj) << endl;
	}
	return 0;
}