/*
Problem Code: 1512B
Time: O(n²)
Space: O(1)
Author: Mohammed Shoaib, github.com/Mohammed-Shoaib
*/

#include <iostream>
#include <string>
#include <vector>
#include <utility>

using namespace std;

void almost_rectangle(int n, vector<string>& grid) {
	vector<pair<int, int>> pos;
	
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			if (grid[i][j] == '*')
				pos.push_back({i, j});
	
	for (int i = 1; i >= 0; i--)
		pos.push_back(pos[i]);
	
	if (pos[0].first == pos[1].first)
		pos[2].first = pos[3].first = (pos[0].first + 1) % n;
	else if (pos[0].second == pos[1].second)
		pos[2].second = pos[3].second = (pos[0].second + 1) % n;
	else
		swap(pos[0].second, pos[1].second);
	
	for (auto& [x, y]: pos)
		grid[x][y] = '*';
	
	for (string& s: grid)
		cout << s << endl;
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		vector<string> grid(n);
		for (string& s: grid)
			cin >> s;
		almost_rectangle(n, grid);
	}
	return 0;
}