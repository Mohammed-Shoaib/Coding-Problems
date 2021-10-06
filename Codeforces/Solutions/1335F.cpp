// Problem Code: 1335F

#include <iostream>
#include <cmath>
#include <string>
#include <vector>
#include <utility>

using namespace std;

pair<int, int> robots(int n, int m, vector<string>& c, vector<string>& s) {
	pair<int, int> res = {};
	int u, limit = ceil(log2(n * m));
	int nxt[n * m][limit + 1];
	pair<bool, bool> robot[n * m] = {};

	// initialize
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) {
			int ni = i, nj = j;
			if (s[i][j] == 'U')
				ni--;
			else if (s[i][j] == 'D')
				ni++;
			else if (s[i][j] == 'L')
				nj--;
			else
				nj++;
			u = i * m + j;
			nxt[u][0] = ni * m + nj;
		}

	// binary lifting
	for (int deg = 1; deg <= limit; deg++)
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++) {
				u = i * m + j;
				nxt[u][deg] = nxt[nxt[u][deg - 1]][deg - 1];
			}
	
	// place valid robots
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) {
			u = i * m + j;
			robot[nxt[u][limit]].first = true;
			robot[nxt[u][limit]].second |= (c[i][j] == '0');
		}

	// calculate placed robots and black cells
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) {
			int u = i * m + j;
			res.first += robot[u].first;
			res.second += robot[u].second;
		}
	
	return res;
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n, m;
		cin >> n >> m;
		vector<string> c(n), s(n);
		for (int i = 0; i < n; i++)
			cin >> c[i];
		for (int i = 0; i < n; i++)
			cin >> s[i];
		pair<int, int> res = robots(n, m, c, s);
		cout << res.first << " " << res.second << endl;
	}
	return 0;
}