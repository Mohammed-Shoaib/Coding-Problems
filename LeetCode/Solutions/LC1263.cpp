/*
Problem Statement: https://leetcode.com/problems/minimum-moves-to-move-a-box-to-their-target-location/
*/

class Solution {
public:
	int minPushBox(vector< vector<char> >& grid) {
		int dist, m, n;
		dist = 0;
		m = grid.size();
		n = grid[0].size();
		pair<int, int> player, box;
		queue< pair<int, int> > qb, qp;

		// Helps go through adjacent positions easily
		vector<int> xdir = {-1, 0, 1, 0};
		vector<int> ydir = {0, -1, 0, 1};
		bool visited[xdir.size()][m][n] = {};

		// Store the player and box position
		for (int i = 0; i < m; i++)
			for (int j = 0; j < n; j++) {
				if (grid[i][j] == 'S')
					player = {i, j};
				else if (grid[i][j] == 'B')
					box = {i, j};
			}
		
		// Start BFS
		qp.push(player);
		qb.push(box);

		while (!qb.empty()) {
			int size = qb.size();
			while (size--) {
				int px, py, bx, by;

				// assign current player position
				px = qp.front().first;
				py = qp.front().second;

				// assign current box position
				bx = qb.front().first;
				by = qb.front().second;

				// pop player and box from queue
				qp.pop();
				qb.pop();

				// Box reached target position
				if (grid[bx][by] == 'T')
					return dist;
				
				for (int i = 0; i < xdir.size(); i++) {
					int new_px, new_py, new_bx, new_by;

					// check for position next to box for player
					new_px = min(max(0, bx + xdir[i]), m - 1);
					new_py = min(max(0, by + ydir[i]), n - 1);

					// final position of box after player moves it
					new_bx = min(max(0, bx - xdir[i]), m - 1);
					new_by = min(max(0, by - ydir[i]), n - 1);

					// check if there is path from current to new position of player
					if (!path({px, py}, {new_px, new_py}, {bx, by}, grid))
						continue;

					if (!visited[i][bx][by] && grid[new_bx][new_by] != '#') {
						visited[i][bx][by] = true;
						qp.push({new_px, new_py});
						qb.push({new_bx, new_by});
					}
				}
			}
			dist++;
		}

		return -1;
	}

	bool path(pair<int, int> player, pair<int, int> target, pair<int, int> box, vector< vector<char> >& grid) {
		int m, n;
		m = grid.size();
		n = grid[0].size();
		queue< pair<int, int> > q;
		bool visited[m][n] = {};

		// Helps go through adjacent positions easily
		vector<int> xdir = {-1, 0, 1, 0};
		vector<int> ydir = {0, -1, 0, 1};

		// cannot step on the box
		if (player == box)
			return false;

		// Start BFS
		visited[player.first][player.second] = true;
		q.push({player});

		while (!q.empty()) {
			int x, y, new_x, new_y;
			x = q.front().first;
			y = q.front().second;
			q.pop();
			
			// check if target reached
			if (x == target.first && y == target.second)
				return true;

			for (int i = 0; i < xdir.size(); i++) {
				// avoid going outside the boundary
				new_x = min(max(0, x + xdir[i]), m - 1);
				new_y = min(max(0, y + ydir[i]), n - 1);

				// cannot step on the box
				if (new_x == box.first && new_y == box.second)
					continue;
				
				// check if positon is valid
				if (!visited[new_x][new_y] && grid[new_x][new_y] != '#') {
					visited[new_x][new_y] = true;
					q.push({new_x, new_y});
				}
			}
		}

		return false;
	}
};