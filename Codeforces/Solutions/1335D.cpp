// Problem Code: 1335D

#include <iostream>
#include <string>
#include <vector>

using namespace std;

void anti_sudoku(vector<string>& grid) {
	for (string& s: grid)
		for (char& c: s)
			if (c == '2')
				c = '1';
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		vector<string> grid(9);
		for (int i = 0; i < grid.size(); i++)
			cin >> grid[i];
		anti_sudoku(grid);
		for (int i = 0; i < grid.size(); i++)
			cout << grid[i] << endl;
	}
	return 0;
}