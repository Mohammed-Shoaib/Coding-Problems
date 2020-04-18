#include <iostream>
#include <string>
#include <vector>

using namespace std;

void alphabet_cake(int R, int C, vector<string>& grid) {
	for (int i = 0; i < R; i++)
		for (int j = 0; j < C; j++)
			if (grid[i][j] != '?') {
				for (int k = j - 1; k >= 0 && grid[i][k] == '?'; k--)
					grid[i][k] = grid[i][j];
				for (int k = j + 1; k < C && grid[i][k] == '?'; k++)
					grid[i][k] = grid[i][j];
			}
	
	for (int i = 0; i < R; i++) {
		if (grid[i][0] == '?')
			continue;
		for (int k = i - 1; k >= 0 && grid[k][0] == '?'; k--)
			grid[k] = grid[i];
		for (int k = i + 1; k < R && grid[k][0] == '?'; k++)
			grid[k] = grid[i];
	}
}

int main() {
	int T;
	cin >> T;
	for (int x = 1; x <= T; x++) {
		int R, C;
		cin >> R >> C;
		vector<string> grid(R);
		for (int i = 0; i < R; i++)
			cin >> grid[i];
		alphabet_cake(R, C, grid);
		cout << "Case #" << x << ":" << endl;
		for (int i = 0; i < R; i++)
			cout << grid[i] << endl;
	}
	return 0;
}