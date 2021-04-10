#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <unordered_map>
#include <functional>

using namespace std;

pair<int, int> wiggle_walk(pair<int, int>& R, string& S) {
	set<pair<int, int>> seen;
	vector<map<pair<int, int>, pair<int, int>>> grid(4);
	unordered_map<char, int> mp = { {'N', 0}, {'W', 1}, {'S', 2}, {'E', 3} };
	
	// traverse directions easily
	vector<int> xdir = {-1, 0, 1, 0};
	vector<int> ydir = {0, -1, 0, 1};
	
	// helper function to update and merge ranges
	function<pair<int, int>(int, pair<int, int>)> dfs = [&](int d, pair<int, int> pos) {
		if (!grid[d].count(pos))
			grid[d][pos] = {pos.first + xdir[d], pos.second + ydir[d]};
		
		pair<int, int>& new_pos = grid[d][pos];
		if (!seen.count(new_pos))
			return new_pos;
		else
			return new_pos = dfs(d, new_pos);
	};
	
	seen.insert(R);
	for (char& c: S) {
		int d = mp[c];
		R = dfs(d, R);
		seen.insert(R);
	}
	
	return R;
}

int main() {
	int T;
	cin >> T;
	for (int x = 1; x <= T; x++) {
		string S;
		int N, R, C;
		pair<int, int> P;
		cin >> N >> R >> C >> P.first >> P.second >> S;
		P = wiggle_walk(P, S);
		cout << "Case #" << x << ": " << P.first << " " << P.second << endl;
	}
	return 0;
}