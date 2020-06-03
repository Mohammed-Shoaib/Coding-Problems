#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <functional>
#include <algorithm>

using namespace std;

string stable_wall(int R, int C, vector<string>& grid) {
	string order;
	bool cycle = false;
	unordered_set<char> letters;
	unordered_map<char, int> visited;
	unordered_map<char, unordered_set<char>> adj;
	
	// helper function
	function<void(char)> dfs = [&](char s) {
		visited[s] = 1;
		for (auto& u: adj[s]) {
			if (visited[u] == 1)
				cycle = true;
			else if (!visited[u])
				dfs(u);
		}
		visited[s] = 2;
		order += s;
	};


	// initialize
	for (int j = 0; j < C; j++)
		letters.insert(grid[R - 1][j]);

	// create adjacency list
	for (int i = R - 2; i >= 0; i--)
		for (int j = 0; j < C; j++) {
			if (grid[i][j] != grid[i + 1][j])
				adj[grid[i + 1][j]].insert(grid[i][j]);
			letters.insert(grid[i][j]);
		}
	
	// topological sort
	for (auto& letter: letters)
		if (!visited[letter])
			dfs(letter);
	reverse(order.begin(), order.end());
	
	return cycle ? "-1" : order;
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
		cout << "Case #" << x << ": " << stable_wall(R, C, grid) << endl;
	}
	return 0;
}