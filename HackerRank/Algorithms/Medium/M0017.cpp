/*
Problem Code: https://www.hackerrank.com/challenges/two-pluses/problem
*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool valid(int i, int j, int top, int bottom, int left, int right, vector<string> &grid) {
	return 	(top >= 0 && bottom < grid.size()) 
			&& (left >= 0 && right < grid[0].size())
			&& (grid[top][j] == 'G' && grid[bottom][j] == 'G')
			&& (grid[i][left] == 'G' && grid[i][right] == 'G');
}

int f(int len) {
	return 4 * max(0, len - 1) + 1;
}

int maximizePlus(vector<string> &grid) {
	int n, m, len;
	n = grid.size();
	m = grid[0].size();
	len = 0;
	vector< vector<int> > top(n, vector<int>(m)), bottom(top), left(top), right(top);

	// Initialize Top & Bottom
	for (int j = 0; j < m; j++) {
		if (grid[0][j] == 'G')
			top[0][j] = 1;
		
		if (grid[n - 1][j] == 'G')
			bottom[n - 1][j] = 1;
	}

	// Initialize Left & Right
	for (int i = 0; i < n; i++) {
		if (grid[i][0] == 'G')
			left[i][0] = 1;
		if (grid[i][m - 1] == 'G')
			right[i][m - 1] = 1;
	}

	for (int i = 1; i < n; i++)
		for (int j = 0; j < m; j++) {
			// Top
			if (grid[i][j] == 'G')
				top[i][j] = top[i - 1][j] + 1;
			else
				top[i][j] = 0;
			
			// Bottom
			int k = n - i - 1;
			if (grid[k][j] == 'G')
				bottom[k][j] = bottom[k + 1][j] + 1;
			else
				bottom[k][j] = 0;
		}

	for (int i = 0; i < n; i++)
		for (int j = 1; j < m; j++) {
			// Left
			if (grid[i][j] == 'G')
				left[i][j] = left[i][j - 1] + 1;
			else
				left[i][j] = 0;

			// Right
			int k = m - j - 1;
			if (grid[i][k] == 'G')
				right[i][k] = right[i][k + 1] + 1;
			else
				right[i][k] = 0;
		}

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			len = max(	min(	min(top[i][j], bottom[i][j]),
								min(left[i][j], right[i][j])),
						len);
	return f(len);
}

int tryPlus(int i, int j, vector<string> grid) {
	int prod, len, top, bottom, left, right;
	prod = len = 0;
	top = bottom = i;
	left = right = j;
	while (valid(i, j, top, bottom, left, right, grid)) {
		len++;
		grid[top--][j] = grid[bottom++][j] = grid[i][left--] = grid[i][right++] = 'B';
		prod = max(maximizePlus(grid) * f(len), prod);
	}
	return prod;
}

int twoPluses(vector<string> &grid) {
	int prod = 0;
	for (int i = 0; i < grid.size(); i++)
		for (int j = 0; j < grid[i].size(); j++)
			prod = max(tryPlus(i, j, grid), prod);
	return prod;
}

int main() {
	int n, m;
	cin >> n >> m;
	vector<string> grid(n);
	for (int i = 0; i < n; i++)
		cin >> grid[i];
	cout << twoPluses(grid);
	return 0;
}