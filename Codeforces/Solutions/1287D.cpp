// Problem Code: 1287D

#include <iostream>
#include <string>
#include <vector>
#include <numeric>
#include <functional>

using namespace std;

void numbers_on_tree(int n, vector<int>& p, vector<int>& c) {
	int root = -1;
	function<int(int)> count;
	function<void(int)> construct;
	vector< vector<int> > ch(n + 1);
	vector<int> cnt(n + 1), val(n + 1), r(n);

	// Create adjacency list of tree
	for (int i = 1; i <= n; i++) {
		if (p[i] == 0)
			root = i;
		else
			ch[p[i]].push_back(i);
	}

	// Count number of children for each node
	count = [&](int node) {
		for (int u: ch[node])
			cnt[node] += 1 + count(u);
		return cnt[node];
	};
	count(root);
	
	// Check if c[i] is greater than number of children
	for (int i = 1; i <= n; i++)
		if (c[i] > cnt[i]) {
			cout << "NO" << endl;
			return;
		}
	
	// Construct values for all nodes
	iota(r.begin(), r.end(), 1);
	construct = [&](int node) {
		val[node] = r[c[node]];
		r.erase(r.begin() + c[node]);
		for (int u: ch[node])
			construct(u);
	};
	construct(root);
	
	// Output solution
	cout << "YES" << endl;
	for (int i = 1; i <= n; i++)
		cout << val[i] << " ";
	cout << endl;
}

int main() {
	int n;
	cin >> n;
	vector<int> p(n + 1), c(n + 1);
	for (int i = 1; i <= n; i++)
		cin >> p[i] >> c[i];
	numbers_on_tree(n, p, c);
	return 0;
}