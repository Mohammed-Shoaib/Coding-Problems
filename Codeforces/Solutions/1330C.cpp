// Problem Code: 1330C

#include <iostream>
#include <vector>

using namespace std;

void coloring(int n, int m, vector<int>& l) {
	bool ok = true;
	vector<long long> p(m), suffix(m + 1);

	for (int i = m - 1; i >= 0; i--)
		suffix[i] += l[i] + suffix[i + 1];

	for (int i = 0; i < m; i++) {
		ok &= (n - l[i] >= i);
		p[i] = max(i + 1LL, n - suffix[i] + 1);
	}
	ok &= (suffix[0] >= n);

	if (!ok)
		cout << "-1" << endl;
	else
		for (int i = 0; i < m; i++)
			cout << p[i] << " ";
}

int main() {
	int n, m;
	cin >> n >> m;
	vector<int> l(m);
	for (int i = 0; i < m; i++)
		cin >> l[i];
	coloring(n, m, l);
	return 0;
}