// Problem Code: 1328E

#include <iostream>
#include <vector>

using namespace std;

int t = 0, root = 1;
vector<vector<int>> adj;
vector<int> d, p, tin, tout;

void dfs(int s, int parent = 0) {
	tin[s] = t++;
	p[s] = parent;
	d[s] = 1 + d[parent];
	for (int u: adj[s])
		if (u != parent)
			dfs(u, s);
	tout[s] = t++;
}

string tree_query(int k, vector<int>& q) {
	int far = root;
	for (int s: q)
		if (d[far] < d[s])
			far = s;
	for (int s: q)
		if (s != far && s != root) {
			s = p[s];
			if (tin[s] > tin[far] || tout[s] < tin[far])
				return "NO";
		}
	return "YES";
}

int main() {
	int n, m, u, v, k;
	cin >> n >> m;
	adj = vector<vector<int>>(n + 1);
	d = p = tin = tout = vector<int>(n + 1);

	for (int i = 0; i < n - 1; i++) {
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	dfs(root);
	for (int i = 0; i < m; i++) {
		cin >> k;
		vector<int> q(k);
		for (int j = 0; j < k; j++)
			cin >> q[j];
		cout << tree_query(k, q) << endl;
	}

	return 0;
}