// Problem Code: 1278C

#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

int empty_jars(int n, vector<int>& a) {
	int jars, di, d;
	unordered_map<int, int> r;
	jars = n << 1;
	di = d = count(a.begin(), a.end(), 1) - count(a.begin(), a.end(), 2);

	r[di] = n - 1;
	for (int i = n; i < a.size(); i++) {
		d += (a[i] == 1) ? -1 : 1;
		if (r.find(d) == r.end())
			r[d] = i;
	}

	d = di;
	if (r.find(0) != r.end())
		jars = min(r[0] - n + 1, jars);
	
	for (int i = n - 1; i >= 0; i--) {
		d += (a[i] == 1) ? -1 : 1;
		if (r.find(di - d) != r.end())
			jars = min(r[di - d] - i + 1, jars);
	}

	return jars;
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		vector<int> a(n << 1);
		for (int i = 0; i < a.size(); i++)
			cin >> a[i];
		cout << empty_jars(n, a) << endl;
	}
	return 0;
}