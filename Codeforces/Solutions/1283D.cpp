// Problem Code: 1283D
 
#include <iostream>
#include <vector>
#include <map>
#include <queue>
 
using namespace std;
 
void christmas_trees(int n, int m, vector<int>& x) {
	long long min_d = 0;
	queue<int> q;
	vector<int> y;
	map<int, int> d;
 
	for (int i = 0; i < n; i++) {
		d[x[i]] = 0;
		q.push(x[i]);
	}
 
	while (y.size() < m && !q.empty()) {
		int pos = q.front();
		q.pop();
		if (d[pos]) {
			min_d += d[pos];
			y.push_back(pos);
		}
		if (!d.count(pos - 1)) {
			d[pos - 1] = d[pos] + 1;
			q.push(pos - 1);
		}
		if (!d.count(pos + 1)) {
			d[pos + 1] = d[pos] + 1;
			q.push(pos + 1);
		}
	}
 
	cout << min_d << endl;
	for (int i = 0; i < m; i++)
		cout << y[i] << " ";
}
 
int main() {
	int n, m;
	cin >> n >> m;
	vector<int> x(n);
	for (int i = 0; i < n; i++)
		cin >> x[i];
	christmas_trees(n, m, x);
	return 0;
}