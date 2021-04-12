#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> cut_sequence(int N, int K, vector<int>& A) {
	int sum = 0;
	vector<int> cuts = { 0 };
	N /= K;
	
	for (int i = 0; i < A.size(); i++) {
		sum += A[i];
		if (sum >= N) {
			sum = 0;
			cuts.push_back(i + 1);
		}
	}
	
	return cuts;
}

string waffle_choppers(int R, int C, int H, int V, vector<string>& grid) {
	int chips = 0;
	vector<int> rows, cols, row_cnt(R), col_cnt(C);
	
	for (int i = 0; i < R; i++)
		for (int j = 0; j < C; j++)
			if (grid[i][j] != '.')
				chips++, row_cnt[i]++, col_cnt[j]++;
	
	rows = cut_sequence(chips, H + 1, row_cnt);
	cols = cut_sequence(chips, V + 1, col_cnt);
	
	for (int a = 1; a < rows.size(); a++)
		for (int b = 1; b < cols.size(); b++) {
			int cnt = 0;
			for (int i = rows[a - 1]; i < rows[a]; i++)
				for (int j = cols[b - 1]; j < cols[b]; j++)
					cnt += grid[i][j] != '.';
			cnt *= (H + 1) * (V + 1);
			if (cnt != chips)
				return "IMPOSSIBLE";
		}
	
	return "POSSIBLE";
}

int main() {
	int T;
	cin >> T;
	for (int x = 1; x <= T; x++) {
		int R, C, H, V;
		cin >> R >> C >> H >> V;
		vector<string> grid(R);
		for (int i = 0; i < R; i++)
			cin >> grid[i];
		cout << "Case #" << x << ": " << waffle_choppers(R, C, H, V, grid) << endl;
	}
	return 0;
}