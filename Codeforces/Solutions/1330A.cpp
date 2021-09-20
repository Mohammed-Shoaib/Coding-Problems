// Problem Code: 1330A

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int ranking(int n, int x, vector<int>& a) {
	int m = *max_element(a.begin(), a.end()) + x;
	vector<bool> mark(m + 1);
	
	for (int v: a)
		mark[v] = true;
	
	for (int i = 1; i <= m && x; i++)
		if (!mark[i]) {
			x--;
			mark[i] = true;
		}
	
	for (int i = 1; i <= m; i++)
		if (!mark[i])
			return i - 1;
	
	return m;
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n, x;
		cin >> n >> x;
		vector<int> a(n);
		for (int i = 0; i < n; i++)
			cin >> a[i];
		cout << ranking(n, x, a) << endl;
	}
	return 0;
}