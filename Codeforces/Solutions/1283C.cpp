// Problem Code: 1283C

#include <iostream>
#include <vector>

using namespace std;

void friends_and_gifts(int n, vector<int>& f) {
	vector<int> r, g;
	vector<bool> known(n + 1);

	for (int i = 0; i < n; i++) {
		known[f[i]] = true;
		if (f[i] == 0)
			g.push_back(i + 1);
	}

	for (int i = 1; i <= n; i++)
		if (!known[i])
			r.push_back(i);
	
	if (r[0] == g[0])
		swap(g[0], g[1]);
	
	for (int i = 1; i < g.size(); i++)
		if (r[i] == g[i])
			swap(g[i - 1], g[i]);
	
	for (int i = 0; i < g.size(); i++)
		f[g[i] - 1] = r[i];
}

int main() {
	int n;
	cin >> n;
	vector<int> f(n);
	for (int i = 0; i < n; i++)
		cin >> f[i];
	friends_and_gifts(n, f);
	for (int i = 0; i < n; i++)
		cout << f[i] << " ";
	return 0;
}