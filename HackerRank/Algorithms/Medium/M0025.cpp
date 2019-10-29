/*
Problem Statement: https://www.hackerrank.com/challenges/knightl-on-chessboard/problem
*/

#include <iostream>
#include <vector>
#include <queue>
#include <tuple>

using namespace std;

bool valid(int x, int y, int n) {
	return (x >= 0 && x < n) && (y >= 0 && y < n);
}

int knightL(int a, int b, int n) {
	int x, y, next_x, next_y, moves;
	vector<int> x_moves, y_moves;
	queue< tuple<int, int, int> > q;
	vector< vector<bool> > visited(n, vector<bool>(n));

	x_moves = {a, a, -a, -a, b, b, -b, -b};
	y_moves = {b, -b, b, -b, a, -a, a, -a};
	visited[0][0] = true;
	q.push({0, 0, 0});
	
	while (!q.empty()) {
		tie(x, y, moves) = q.front();
		q.pop();
		
		for (int i = 0; i < x_moves.size(); i++) {
			next_x = x + x_moves[i];
			next_y = y + y_moves[i];
			
			if (next_x == n - 1 && next_y == n - 1)
				return moves + 1;
			else if (valid(next_x, next_y, n) && !visited[next_x][next_y]) {
				visited[next_x][next_y] = true;
				q.push({next_x, next_y, moves + 1});
			}
		}
	}

	return -1;
}

vector< vector<int> > knightLOnAChessboard(int n) {
	vector< vector<int> > moves(n - 1, vector<int>(n - 1));
	for (int i = 1; i < n; i++)
		for (int j = 1; j < n; j++)
			moves[i - 1][j - 1] = knightL(i, j, n);
	return moves;
}

int main() {
	int n;
	cin >> n;
	vector< vector<int> > moves = knightLOnAChessboard(n);
	for (int i = 0; i < moves.size(); i++) {
		for (int j = 0; j < moves[i].size(); j++)
			cout << moves[i][j] << " ";
		cout << endl;
	}
	return 0;
}