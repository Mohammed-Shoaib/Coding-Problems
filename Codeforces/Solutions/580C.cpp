// Problem Code: 580C
 
#include <iostream>
#include <vector>
#include <functional>

using namespace std;

int kefa_and_park(int n, int m, vector<int>& a, vector<vector<int>>& adj) {
	int cnt = 0;
	
	function<void(int, int, int)> dfs = [&](int s, int par, int cats) {
		if (a[s])
			cats++;
		else
			cats = 0;
		
		if (cats > m)
			return;
		
		bool is_leaf = true;
		for (int u: adj[s])
			if (u != par) {
				is_leaf = false;
				dfs(u, s, cats);
			}
		
		if (is_leaf)
			cnt++;
	};
	dfs(0, -1, 0);
	
	return cnt;
}

int main() {
	int n, m;
	cin >> n >> m;
	vector<int> a(n);
	vector<vector<int>> adj(n);
	
	for (int& x: a)
		cin >> x;
	
	for (int i = 0; i < n - 1; i++) {
		int x, y;
		cin >> x >> y;
		adj[x - 1].push_back(y - 1);
		adj[y - 1].push_back(x - 1);
	}
	
	cout << kefa_and_park(n, m, a, adj);
	
	return 0;
}
