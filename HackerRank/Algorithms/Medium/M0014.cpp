/*
Problem Statement: https://www.hackerrank.com/challenges/bomber-man/problem
*/

#include <iostream>
#include <vector>

using namespace std;

vector<string> bomberMan(int n, int r, int c, vector<string> &grid) {
	if (n == 1)
		return grid;
	
	int size = 4;
	vector< vector<string> > second(size, vector<string>(r, string(c, 'O')));

	for (int t = 1; t < size; grid = second[t], t += 2)
		for (int i = 0; i < r; i++)
			for (int j = 0; j < c; j++)
				if (grid[i][j] == 'O')
					second[t][i][j] 
					= second[t][min(r - 1, i + 1)][j]
					= second[t][i][min(c - 1, j + 1)]
					= second[t][max(0, i - 1)][j]
					= second[t][i][max(0, j - 1)]
					= '.';

	return second[(n - 2) % size];
}

int main() {
	int r, c, n;
	cin >> r >> c >> n;
	vector<string> grid(r);
	for (int i = 0; i < r; i++)
		cin >> grid[i];
	grid = bomberMan(n, r, c, grid);
	for (int i = 0; i < r; i++)
		cout << grid[i] << endl;
	return 0;
}