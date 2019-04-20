#include <iostream>
#include <cstdio>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

bool valid(int i, int j, int L) {
	return (i >= 0 && i < L && j >= 0 && j < L);
}

void dfs(int &k, int i, int j, vector< vector<bool> > &visited, vector< vector<char> > &grid) {
	visited[i][j] = true;
	for (int y = -1; y <= 1; y++)
		for (int x = -1; x <= 1; x++)
			if ((y != 0 || x != 0) &&
				valid(y + i, x + j, grid.size()) &&
				!visited[y + i][x + j] &&
				grid[i][j] == grid[y + i][x + j])
				dfs(++k, y + i, x + j, visited, grid);
}

int fruit(int L, int n, unordered_map<char, int> &p, vector< vector<char> > &grid) {
	char c;
	int k, max_burst = 0;
	vector< vector<bool> > visited(L, vector<bool>(L));
	for (int i = 0; i < L; i++)
		for (int j = 0; j < L; j++)
			if (!visited[i][j]) {
				k = 1;
				c = grid[i][j];
				dfs(k, i, j, visited, grid);
				if (p.find(c) == p.end())
					p[c] = p['#'];
				if (n <= k)
					max_burst = max(k * p[c], max_burst);
			}
	return max_burst;
}

int main() {
	freopen("fruit.in", "r", stdin);
	freopen("output.out", "w", stdout);
	
	int L, n;
	while (cin >> L && L) {
		cin >> n;
		char c;
		int points;
		unordered_map<char, int> p;
		vector< vector<char> > grid(L, vector<char>(L));
		for (int i = 0; i < L; i++)
			for (int j = 0; j < L; j++)
				cin >> grid[i][j];
		while (cin >> c) {
			cin >> points;
			p[c] = points;
			if (c == '#')
				break;
		}
		cout << fruit(L, n, p, grid) << endl;
	}

	return 0;
}