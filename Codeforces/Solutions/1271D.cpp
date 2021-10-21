// Problem Code: 1271D

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int portals(int n, int k, vector<int>& a, vector<int>& b, vector<int>& c, vector<int>& far) {
	int imp = 0;
	vector< vector<int> > adj(n, vector<int>());
	priority_queue<int, vector<int>, greater<int>> pq;

	// Initialize adjacency list for portals
	for (int i = 0; i < n; i++)
		if (far[i] != -1)
			adj[far[i]].push_back(i);
	
	for (int i = 0; i < n; i++) {
		// Undo defended castles to get warriors from min heap
		while (k < a[i] && !pq.empty()) {
			pq.pop();
			k++;
		}
		
		// We cannot win the game
		if (k < a[i])
			return -1;

		// Capture current castle
		k += b[i];

		// Defend castle because it has no incoming portal from future castles
		if (far[i] == -1) {
			pq.push(c[i]);
			k--;
		}

		// Defend previous castles using portals of current castle
		for (int v: adj[i]) {
			pq.push(c[v]);
			k--;
		}
	}

	// Sum importance values of all defended castles
	while (!pq.empty()) {
		if (k >= 0)
			imp += pq.top();
		pq.pop();
		k++;
	}

	return imp;
}

int main() {
	int n, m, k, u, v;
	cin >> n >> m >> k;
	vector<int> a(n), b(n), c(n), far(n, -1);
	
	for (int i = 0; i < n; i++)
		cin >> a[i] >> b[i] >> c[i];
	for (int i = 0; i < m; i++) {
		cin >> u >> v;
		far[v - 1] = max(u - 1, far[v - 1]);
	}
	cout << portals(n, k, a, b, c, far);
	
	return 0;
}