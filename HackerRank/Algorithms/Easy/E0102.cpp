/*
Problem Statement: https://www.hackerrank.com/challenges/a-chessboard-game-1/problem
*/

#include <iostream>

using namespace std;

string chessboardGame(int x, int y) {
	int winner = ((x - 1) % 4) / 2;
	winner |= ((y - 1) % 4) / 2;
	return winner ? "First" : "Second";
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		int x, y;
		cin >> x >> y;
		cout << chessboardGame(x, y) << endl;
	}
	return 0;
}