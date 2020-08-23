#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

string largest(int n, vector<string> &m) {
	sort(m.rbegin(), m.rend(), [](string &l, string &r) {
		return (l + r) < (r + l);
	});
	return accumulate(m.begin(), m.end(), string(""));
}

int main() {
	freopen("largest.in", "r", stdin);
	freopen("output.out", "w", stdout);
	
	int k;
	cin >> k;
	while (k--) {
		int n;
		cin >> n;
		vector<string> m(n);
		for (int i = 0; i < n; i++)
			cin >> m[i];
		cout << largest(n, m) << endl;
	}
	
	return 0;
}