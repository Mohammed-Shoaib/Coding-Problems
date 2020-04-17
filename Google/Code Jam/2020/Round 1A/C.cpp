#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <functional>

using namespace std;

long long square_dance(int R, int C, vector<vector<int>>& S) {
	bool flag = true;
	long long interest, alive;
	interest = alive = 0;
	vector<vector<int>> l(R, vector<int>(C));
	vector<vector<int>> u(R, vector<int>(C));
	vector<vector<int>> r(R, vector<int>(C));
	vector<vector<int>> d(R, vector<int>(C));
	vector<vector<bool>> mark(R, vector<bool>(C));
	vector<pair<int, int>> round, neighbours;

	// adds the dancer to the next round if it should be eliminated
	auto eliminate = [&](int i, int j) {
		int sum, n;
		sum = n = 0;
		if (l[i][j] != -1) {
			sum += S[i][l[i][j]];
			n++;
		}
		if (r[i][j] != -1) {
			sum += S[i][r[i][j]];
			n++;
		}
		if (u[i][j] != -1) {
			sum += S[u[i][j]][j];
			n++;
		}
		if (d[i][j] != -1) {
			sum += S[d[i][j]][j];
			n++;
		}
		if (!mark[i][j] && n * S[i][j] < sum) {
			mark[i][j] = true;
			round.emplace_back(i, j);
		}
	};

	// removes the dancer and adds its neighbours
	auto remove = [&](int i, int j) {
		alive -= S[i][j];
		if (l[i][j] != -1) {
			r[i][l[i][j]] = r[i][j];
			neighbours.emplace_back(i, l[i][j]);
		}
		if (r[i][j] != -1) {
			l[i][r[i][j]] = l[i][j];
			neighbours.emplace_back(i, r[i][j]);
		}
		if (u[i][j] != -1) {
			d[u[i][j]][j] = d[i][j];
			neighbours.emplace_back(u[i][j], j);
		}
		if (d[i][j] != -1) {
			u[d[i][j]][j] = u[i][j];
			neighbours.emplace_back(d[i][j], j);
		}
	};

	// initialization
	for (int i = 0; i < R; i++)
		for (int j = 0; j < C; j++) {
			alive += S[i][j];
			l[i][j] = j - 1;
			r[i][j] = (j < C - 1) ? j + 1 : -1;
			u[i][j] = i - 1;
			d[i][j] = (i < R - 1) ? i + 1 : -1;
		}
	
	// add dancers to be eliminated
	for (int i = 0; i < R; i++)
		for (int j = 0; j < C; j++)
			eliminate(i, j);

	// simulate the process
	while (flag) {
		flag = !round.empty();
		interest += alive;
		neighbours.clear();
		for (auto& p: round)
			remove(p.first, p.second);
		round.clear();
		for (auto& p: neighbours)
			eliminate(p.first, p.second);
	}

	return interest;
}

int main() {
	int T;
	cin >> T;
	for (int x = 1; x <= T; x++) {
		int R, C;
		cin >> R >> C;
		vector<vector<int>> S(R, vector<int>(C));
		for (int i = 0; i < R; i++)
			for (int j = 0; j < C; j++)
				cin >> S[i][j];
		cout << "Case #" << x << ": " << square_dance(R, C, S) << endl;
	}
}