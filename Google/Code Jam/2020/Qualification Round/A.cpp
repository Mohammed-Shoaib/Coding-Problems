#include <iostream>
#include <cstdio>
#include <vector>
#include <unordered_set>

using namespace std;

vector<int> vestigium(int N, vector<vector<int>>& M) {
	int k, r, c;
	k = r = c = 0;
	for (int i = 0; i < N; i++) {
		unordered_set<int> row, col;
		for (int j = 0; j < N; j++) {
			row.insert(M[i][j]);
			col.insert(M[j][i]);
		}
		k += M[i][i];
		r += row.size() != N;
		c += col.size() != N;
	}
	return {k, r, c};
}

int main() {
	int T;
	cin >> T;
	for (int x = 1; x <= T; x++) {
		int N;
		cin >> N;
		vector<vector<int>> M(N, vector<int>(N));
		for (int i = 0; i < N; i++)
			for (int j = 0; j < N; j++)
				cin >> M[i][j];
		vector<int> res = vestigium(N, M);
		printf("Case #%d: %d %d %d\n", x, res[0], res[1], res[2]);
	}
	return 0;
}