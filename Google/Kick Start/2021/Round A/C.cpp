#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int64_t rabbit_house(int R, int C, vector<vector<int>>& grid) {
	int64_t cnt = 0;
	
	// subtract the initial heights
	for (int i = 0; i < R; i++)
		for (int j = 0; j < C; j++)
			cnt -= grid[i][j];
	
	// take the maximum from left to right
	for (int i = 0; i < R; i++)
		for (int j = 1; j < C; j++)
			grid[i][j] = max(grid[i][j - 1] - 1, grid[i][j]);
	
	// take the maximum from right to left
	for (int i = 0; i < R; i++)
		for (int j = C - 2; j >= 0; j--)
			grid[i][j] = max(grid[i][j + 1] - 1, grid[i][j]);
	
	// take the maximum from top to bottom
	for (int i = 1; i < R; i++)
		for (int j = 0; j < C; j++)
			grid[i][j] = max(grid[i - 1][j] - 1, grid[i][j]);
	
	// take the maximum from bottom to top
	for (int i = R - 2; i >= 0; i--)
		for (int j = 0; j < C; j++)
			grid[i][j] = max(grid[i + 1][j] - 1, grid[i][j]);
	
	// add the updated heights
	for (int i = 0; i < R; i++)
		for (int j = 0; j < C; j++)
			cnt += grid[i][j];
	
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
		
		cout << "Case #" << x << ": " << rabbit_house(R, C, grid) << endl;
	}
	return 0;
}