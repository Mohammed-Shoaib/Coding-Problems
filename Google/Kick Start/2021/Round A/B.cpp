#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int l_shaped_plots(int R, int C, vector<vector<int>>& grid) {
	int cnt = 0;
	
	for (int flip_row: {0, 1}) {
		for (int flip_col: {0, 1}) {
			vector<int> row(R), col(C);
			
			// count the number of L shapes
			for (int i = 0; i < R; i++)
				for (int j = 0; j < C; j++) {
					if (grid[i][j])
						row[i]++, col[j]++;
					else
						row[i] = col[j] = 0;
					
					cnt += max(0, min(row[i], col[j] / 2) - 1);
					cnt += max(0, min(row[i] / 2, col[j]) - 1);
				}
			
			// flip horizontally
			for (int i = 0; i < R; i++)
				reverse(grid[i].begin(), grid[i].end());
		}
		
		// flip vertically
		for (int i = 0; i < R / 2; i++)
			for (int j = 0; j < C; j++)
				swap(grid[i][j], grid[R - i - 1][j]);
	}
	
	return cnt;
}

int main() {
	int T;
	cin >> T;
	for (int x = 1; x <= T; x++) {
		int R, C;
		cin >> R >> C;
		vector<vector<int>> grid(R, vector<int>(C));
		
		for (int i = 0; i < R; i++)
			for (int j = 0; j < C; j++)
				cin >> grid[i][j];
		
		cout << "Case #" << x << ": " << l_shaped_plots(R, C, grid) << endl;
	}
	return 0;
}