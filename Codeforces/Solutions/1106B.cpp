// Problem Code: 1106B

#include <iostream>
#include <vector>
#include <queue>
#include <utility>

using namespace std;

typedef priority_queue< pair<int, int>, 
						vector< pair<int, int> >, 
						greater< pair<int, int> > > PQ;

int findCheapest(vector<int> &a, PQ &pq) {
	while (!pq.empty() && a[pq.top().second] == 0)
		pq.pop();
	return (pq.empty()) ? 0 : pq.top().second;
}

long long calculateCost(int u, int v, vector<int> &a, vector<int> &c, vector<int> &d) {
	long long cost;
	if (d[u] <= a[v]) {
		a[v] -= d[u];
		cost = (long long) d[u] * c[v];
		d[u] = 0;
	} else {
		d[u] -= a[v];
		cost = (long long) a[v] * c[v];
		a[v] = 0;
	}
	return cost;
}

vector<long long> foodOrdering(int n, int m, vector<int> &a, vector<int> &c, vector<int> &t, vector<int> &d) {
	int pos;
	vector<long long> cost(m + 1);
	PQ pq;

	for (int i = 1; i <= n; i++)
		pq.push(make_pair(c[i], i));
	
	for (int i = 1; i <= m; i++) {
		cost[i] = calculateCost(i, t[i], a, c, d);
		if (d[i] == 0)
			continue;
		pos = findCheapest(a, pq);
		while (pos != 0 && d[i] != 0) {
			cost[i] += calculateCost(i, pos, a, c, d);
			pos = findCheapest(a, pq);
		}
		if (d[i] != 0)
			cost[i] = 0;
	}

	return cost;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m;
	vector<long long> cost;
	cin >> n >> m;

	vector<int> a(n + 1), c(n + 1), t(m + 1), d(m + 1);
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	for (int i = 1; i <= n; i++)
		cin >> c[i];
	for (int i = 1; i <= m; i++)
		cin >> t[i] >> d[i];
	
	cost = foodOrdering(n, m, a, c, t, d);
	for (int i = 1; i <= m; i++)
		cout << cost[i] << "\n";
	
	return 0;
}