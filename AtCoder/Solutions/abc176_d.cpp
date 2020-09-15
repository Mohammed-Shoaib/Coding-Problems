// Problem Code: abc176_d

#include <iostream>
#include <vector>
#include <string>
#include <deque>
#include <tuple>
#include <utility>

using namespace std;

int wizard_in_maze(int H, int W, pair<int, int>& C, pair<int, int>& D, vector<string>& S) {
	deque<pair<int, int>> q;
	vector<vector<int>> dist(H, vector<int>(W, 1e9));
	
	// traverse directions easily
	vector<int> xdir = {-1, 0, 1, 0};
	vector<int> ydir = {0, -1, 0, 1};
	
	// helper function
	auto valid = [&](int x, int y) {
		return x >= 0 && x < H 
			&& y >= 0 && y < W
			&& S[x][y] == '.';
	};
	
	// initialization
	q.push_front(C);
	dist[C.first][C.second] = 0;
	
	// 0/1 BFS
	while (!q.empty()) {
		int x, y;
		tie(x, y) = q.front();
		q.pop_front();
		
		// reached target
		if (x == D.first && y == D.second)
			return dist[x][y];
		
		// use move a
		for (int k = 0; k < xdir.size(); k++) {
			int nx = x + xdir[k], ny = y + ydir[k];
			if (valid(nx, ny) && dist[nx][ny] > dist[x][y]) {
				q.push_front({nx, ny});
				dist[nx][ny] = dist[x][y];
			}
		}
		
		// use move b
		for (int nx = -2 + x; nx <= 2 + x; nx++)
			for (int ny = -2 + y; ny <= 2 + y; ny++)
				if (valid(nx, ny) && dist[nx][ny] > dist[x][y] + 1) {
					q.push_back({nx, ny});
					dist[nx][ny] = dist[x][y] + 1;
				}
	}
	
	return -1;
}

int main() {
	int H, W;
	pair<int, int> C, D;
	cin >> H >> W >> C.first >> C.second >> D.first >> D.second;
	C.first--, C.second--, D.first--, D.second--;
	vector<string> S(H);
	for (int i = 0; i < H; i++)
		cin >> S[i];
	cout << wizard_in_maze(H, W, C, D, S);
	return 0;
}