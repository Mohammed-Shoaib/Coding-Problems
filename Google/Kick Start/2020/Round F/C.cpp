#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <functional>

using namespace std;

int painters_duel(int S, pair<int, int>& A, pair<int, int>& B, int C, vector<pair<int, int>>& D) {
	vector<int> rooms(2);
	vector<vector<bool>> visited(S + 1, vector<bool>(2 * S));
	
	// traverse directions easily
	vector<int> xdir = {0, -1, 0, 1};
	vector<int> ydir = {-1, -1, 1, 1};
	
	// helper function to check for a position
	auto valid = [&](pair<int, int> pos) {
		return pos.first > 0 && pos.first <= S
			&& pos.second > 0 && pos.second <= 2 * pos.first - 1
			&& !visited[pos.first][pos.second];
	};
	
	// helper function to traverse a state
	function<int(int, vector<pair<int, int>>, vector<bool>)> state = [&](bool turn, vector<pair<int, int>> pos, vector<bool> found) {
		vector<int> scores;
		
		// update state parameters
		rooms[turn]++;
		found[turn] = false;
		
		// move the player to next state
		for (int k = 0; k < xdir.size(); k++) {
			if (xdir[k] == 1 && pos[turn].second % 2 == 0 || xdir[k] == -1 && pos[turn].second % 2 == 1)
				continue;
	
			vector<pair<int, int>> new_pos = pos;
			new_pos[turn].first = pos[turn].first + xdir[k];
			new_pos[turn].second = pos[turn].second + ydir[k];
			
			if (valid(new_pos[turn])) {
				found[turn] = true;
				visited[new_pos[turn].first][new_pos[turn].second] = true;
				scores.push_back(state(turn ^ 1, new_pos, found));
				visited[new_pos[turn].first][new_pos[turn].second] = false;
			}
		}
		rooms[turn]--;
		
		// calculate score of path
		if (found[turn]) {
			if (turn)
				return *min_element(scores.begin(), scores.end());
			else
				return *max_element(scores.begin(), scores.end());
		} else {
			if (!found[turn ^ 1])
				return rooms[0] - rooms[1];
			else
				return state(turn ^ 1, pos, found);
		}
	};
	
	visited[A.first][A.second] = true;
	visited[B.first][B.second] = true;
	for (pair<int, int>& room: D)
		visited[room.first][room.second] = true;
	
	return state(0, {A, B}, {true, true});
}

int main() {
	int T;
	cin >> T;
	
	for (int x = 1; x <= T; x++) {
		int S, C;
		pair<int, int> A, B;
		cin >> S >> A.first >> A.second >> B.first >> B.second >> C;
		vector<pair<int, int>> D(C);
		
		for (int i = 0; i < C; i++)
			cin >> D[i].first >> D[i].second;
		
		cout << "Case #" << x << ": " << painters_duel(S, A, B, C, D) << endl;
	}
	
	return 0;
}