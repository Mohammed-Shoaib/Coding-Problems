// Problem Code: 1333E

#include <iostream>
#include <vector>
#include <tuple>

using namespace std;

void build_board(int N) {
	// impossible
	if (N <= 2) {
		cout << "-1" << endl;
		return;
	}

	// choose start points
	int d, i, j, cnt = 1, len = N;
	if (N & 1)
		tie(d, i, j) = make_tuple(0, N - 1, 0);
	else
		tie(d, i, j) = make_tuple(2, 0, N - 1);
	
	// base case, N = 3
	vector<vector<int>> board(N, vector<int>(N)), base = {
		{5, 9, 4},
		{6, 8, 3},
		{1, 2, 7}
	};
	
	// directions: right, up, down, left
	vector<int> x_dir = {0, -1, 1,  0};
	vector<int> y_dir = {1,  0, 0, -1};
	
	// construct snake line
	while (len > 0) {
		// move len units
		for (int k = 1; k <= len; k++, i += x_dir[d], j += y_dir[d]) {
			if (len <= 3)
				board[i][j] = cnt + base[i][j] - 1;
			else
				board[i][j] = cnt++;
			d += (k == len);
		}
		// move len - 1 units
		for (int k = 1; k <= len - 1; k++, i += x_dir[d], j += y_dir[d]) {
			if (len <= 3)
				board[i][j] = cnt + base[i][j] - 1;
			else
				board[i][j] = cnt++;
		}
		// reset for next round
		len--;
		d = (d + 1) % x_dir.size();
		i += (d == 0) ? -1 :  1;
		j += (d == 0) ?  1 : -1;
	}
	
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++)
			cout << board[i][j] << " ";
		cout << endl;
	}
}

int main() {
	int N;
	cin >> N;
	build_board(N);
	return 0;
}