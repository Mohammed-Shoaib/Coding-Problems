// Problem Code: 1281D

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int beingawesomeism(int r, int c, vector<string>& grid) {
	int a = 0;
	vector<int> rows(r), cols(c);
	
	for (int i = 0; i < r; i++)
		for (int j = 0; j < c; j++)
			if (grid[i][j] == 'A') {
				a++;
				rows[i]++;
				cols[j]++;
			}
	
	if (a == 0)
		return -1;
	else if (a == r * c)
		return 0;
	else if (rows[0] == c || rows[r - 1] == c || cols[0] == r || cols[c - 1] == r)
		return 1;
	else if (grid[0][0] == 'A' || grid[0][c - 1] == 'A' || grid[r - 1][0] == 'A' || grid[r - 1][c - 1] == 'A')
		return 2;
	else if (*max_element(rows.begin(), rows.end()) == c || *max_element(cols.begin(), cols.end()) == r)
		return 2;
	else if (rows[0] || rows[r - 1] || cols[0] || cols[c - 1])
		return 3;
	else
		return 4;
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		int r, c, usage;
		cin >> r >> c;
		vector<string> grid(r);
		for (int i = 0; i < r; i++)
			cin >> grid[i];
		usage = beingawesomeism(r, c, grid);
		if (usage != -1)
			cout << usage << endl;
		else
			cout << "MORTAL" << endl;
	}
	return 0;
}