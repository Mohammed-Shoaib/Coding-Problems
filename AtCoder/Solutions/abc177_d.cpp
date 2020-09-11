// Problem Code: abc177_d

#include <iostream>
#include <vector>
#include <functional>

using namespace std;

int friends(int N, int M, vector<vector<int>>& adj) {
	int len, max_len = 0;
	vector<bool> visited(N);
	
	// helper function
	function<void(int)> dfs = [&](int s) {
		visited[s] = true;
		max_len = max(++len, max_len);
		for (int& u: adj[s])
			if (!visited[u])
				dfs(u);
	};
	
	// visit each component
	for (int i = 0; i < N; i++)
		if (!visited[i]) {
			len = 0;
			dfs(i);
		}
	
	return max_len;
}

int main() {
	int N, M;
	cin >> N >> M;
	vector<vector<int>> adj(N);
	for (int i = 0; i < M; i++) {
		int A, B;
		cin >> A >> B;
		--A, --B;
		adj[A].push_back(B);
		adj[B].push_back(A);
	}
	cout << friends(N, M, adj);
	return 0;
}