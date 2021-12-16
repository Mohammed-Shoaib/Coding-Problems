// Problem Code: 1330B

#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

vector<int> permutations(int n, vector<int>& a) {
	vector<int> p;
	vector<bool> l(n), r(n);
	unordered_set<int> seen;

	for (int max_v = 0, i = 0; i < n && !seen.count(a[i]); i++) {
		seen.insert(a[i]);
		max_v = max(a[i], max_v);
		l[i] = (seen.size() == max_v);
	}

	seen.clear();
	for (int max_v = 0, i = n - 1; i >= 0 && !seen.count(a[i]); i--) {
		seen.insert(a[i]);
		max_v = max(a[i], max_v);
		r[i] = (seen.size() == max_v);
	}

	for (int i = 1; i < n; i++)
		if (l[i - 1] && r[i])
			p.push_back(i);
	
	return p;
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		vector<int> a(n), p;
		for (int i = 0; i < n; i++)
			cin >> a[i];
		p = permutations(n, a);
		cout << p.size() << endl;
		for (int x: p)
			cout << x << " " << n - x << endl;
	}
	return 0;
}