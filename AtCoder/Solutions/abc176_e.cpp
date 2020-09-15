// Problem Code: abc176_e

#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

int bomber(int H, int W, int M, vector<int>& h, vector<int>& w) {
	int max_bombs, max_row, max_col;
	set<pair<int, int>> seen;
	vector<int> candidate_rows, candidate_cols, rows(H), cols(W);
	
	for (int i = 0; i < M; i++) {
		rows[h[i]]++;
		cols[w[i]]++;
		seen.emplace(h[i], w[i]);
	}
	
	max_row = *max_element(rows.begin(), rows.end());
	max_col = *max_element(cols.begin(), cols.end());
	max_bombs = max_row + max_col - 1;
	
	for (int i = 0; i < H; i++)
		if (rows[i] == max_row)
			candidate_rows.push_back(i);
	for (int i = 0; i < W; i++)
		if (cols[i] == max_col)
			candidate_cols.push_back(i);
	
	for (int& row: candidate_rows)
		for (int& col: candidate_cols)
			if (!seen.count({row, col}))
				return 1 + max_bombs;
	
	return max_bombs;
}

int main() {
	int H, W, M;
	cin >> H >> W >> M;
	vector<int> h(M), w(M);
	for (int i = 0; i < M; i++) {
		cin >> h[i] >> w[i];
		h[i]--, w[i]--;
	}
	cout << bomber(H, W, M, h, w);
	return 0;
}