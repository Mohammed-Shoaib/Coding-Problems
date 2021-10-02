// Problem Code: 1114B

#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

void partition(int n, int m, int k, vector<int> a) {
	long long sum;
	vector<int> p(m * k);
	vector< pair<int, int> > pos(n);
	sum = 0;
	for (int i = 0; i < n; i++)
		pos[i] = make_pair(a[i], i);
	sort(pos.rbegin(), pos.rend());
	for (int i = 0; i < m * k; i++) {
		sum += pos[i].first;
		p[i] = pos[i].second;
	}
	sort(p.begin(), p.end());
	cout << sum << endl;
	for (int i = 0; i < k - 1; i++)
		cout << p[(i + 1) * m - 1] + 1<< " ";
}

int main() {
	int n, m, k;
	cin >> n >> m >> k;
	vector<int> a(n);
	for (int i = 0; i < n; i++)
		cin >> a[i];
	partition(n, m, k, a);
	return 0;
}