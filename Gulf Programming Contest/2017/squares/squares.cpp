#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

string win(char c) {
	return (c == 'M') ? "I Win!" : "I Lose!";
}

string lose(char c) {
	return (c == 'M') ? "I Lose!" : "I Win!";
}

string squares(int S, int C, char start) {
	int moves;
	vector<int> count({min(S, C), max(S, C)});
	moves = count[0] / 2;
	if (count[0] & 1) {
		count[1]--;
		moves++;
	}
	moves += count[1] / 2;
	return (moves & 1) ? win(start) : lose(start);
}

int main() {
	freopen("squares.in", "r", stdin);
	freopen("output.out", "w", stdout);
	
	int k, T;
	k = 1;
	cin >> T;
	while (T--) {
		int S, C;
		char start;
		cin >> S >> C >> start;
		cout << k << ". " << squares(S, C, start) << endl;
		k++;
	}
	return 0;
}