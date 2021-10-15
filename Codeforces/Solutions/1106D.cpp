// Problem Code: 1106D

#include <iostream>
#include <vector>
#include <queue>
#include <functional>

using namespace std;

vector<int> bobTheWanderer(int n, int m, vector<int> u, vector<int> v) {
	int top;
	vector<int> seq;
	vector<bool> visited(n + 1);
	vector< vector<int> > adj(n + 1, vector<int> (1));
	priority_queue< int, vector<int>, greater<int> > pq;
	
	for (int i = 0; i < m; i++) {
		adj[u[i]].push_back(v[i]);
		adj[v[i]].push_back(u[i]);
	}
	
	pq.push(1);
	visited[pq.top()] = true;
	
	while (!pq.empty()) {
		top = pq.top();
		pq.pop();
		seq.push_back(top);
		for (int i = 1; i < adj[top].size(); i++)
			if (!visited[adj[top][i]]) {
				pq.push(adj[top][i]);
				visited[adj[top][i]] = true;
			}
	}

	return seq;
}

int main() {
	int n, m;
	cin >> n >> m;
	vector<int> u(m), v(m), seq;
	for (int i = 0; i < m; i++)
		cin >> u[i] >> v[i];
	seq = bobTheWanderer(n, m, u, v);
	for (int i = 0; i < n; i++)
		cout << seq[i] << " ";
	cout << endl;
	return 0;
}