// Problem Code: 1333D

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

void head_turns(int n, int k, string& s) {
	int i, j, mx = 0;
	bool done = false;
	vector<vector<int>> moves;

	while (!done) {
		done = true;
		vector<int> move;
		for (int i = 0; i < n - 1; i++)
			if (s[i] == 'R' && s[i + 1] == 'L') {
				mx++;
				done = false;
				swap(s[i], s[i + 1]);
				move.push_back(++i);
			}
		if (!done)
			moves.push_back(move);
	}
	
	if (moves.size() > k || mx < k) {
		cout << "-1" << '\n';
		return;
	}

	// endl is slow as it flushes the buffer each time hence '\n'
	i = j = 0;
	while (i < moves.size()) {
		if (moves.size() - i < k)
			cout << 1 << " " << moves[i][j++] << '\n';
		else {
			cout << moves[i].size() - j;
			while (j < moves[i].size())
				cout << " " << moves[i][j++];
			cout << '\n';
		}
		if (j == moves[i].size()) {
			j = 0;
			i++;
		}
		k--;
	}
}

int main() {
	int n, k;
	string s;
	cin >> n >> k >> s;
	head_turns(n, k, s);
	return 0;
}