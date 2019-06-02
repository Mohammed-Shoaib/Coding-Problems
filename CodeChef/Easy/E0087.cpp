// Problem Code: FIRESC

#include <iostream>
#include <vector>

using namespace std;

const int mod = 1e9 + 7;

void DFS(int s, int &count, vector<bool> &visited, vector< vector<int> > &adj) {
	count++;
	visited[s] = true;
	for (auto u: adj[s])
		if (!visited[u])
			DFS(u, count, visited, adj);
}

void fireEscapeRoutes(int N, vector< vector<int> > &adj) {
	int routes = 0;
	long long ways = 1;
	vector<bool> visited(N + 1);
	for (int i = 1; i <= N; i++)
		if (!visited[i]) {
			int count = 0;
			DFS(i, count, visited, adj);
			ways = (ways * count) % mod;
			routes++;
		}
	cout << routes << " " << ways << endl;
}

int main() {
	int T;
	cin >> T;
	while (T--) {
		int N, M, i, j;
		cin >> N >> M;
		vector< vector<int> > adj(N + 1);
		for (int k = 0; k < M; k++) {
			cin >> i >> j;
			adj[i].push_back(j);
			adj[j].push_back(i);
		}
		fireEscapeRoutes(N, adj);
	}
	return 0;
}