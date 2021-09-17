// Problem Code: 1284A

#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
	int n, m, q, y;
	cin >> n >> m;
	vector<string> s(n), t(m);
	for (int i = 0; i < n; i++)
		cin >> s[i];
	for (int i = 0; i < m; i++)
		cin >> t[i];
	cin >> q;
	while (q--) {
		cin >> y;
		y--;
		cout << s[y % n] + t[y % m] << endl;
	}
	return 0;
}