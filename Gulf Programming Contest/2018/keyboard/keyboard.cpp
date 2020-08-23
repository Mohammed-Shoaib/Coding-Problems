#include <iostream>
#include <cstdio>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

bool valid(int i, int j, int y, int x) {
	return ((i + y >= 0 && i + y <= 3) && (j + x >= 0 && j + x <= 2));
}

string keyboard(int r, string seq) {
	int i, j;
	string s = "";
	vector<int> x = {-1, 0, 1, 0};
	vector<int> y = {0, -1, 0, 1};
	unordered_map<char, int> map = { {'L', 0},
									 {'U', 1},
									 {'R', 2},
									 {'D', 3} };
	vector< vector<char> > b = { {'1', '2', '3'},
								 {'4', '5', '6'},
								 {'7', '8', '9'},
								 {'*', '0', '#'} };
	i = j = 1;
	r /= 90;
	r = x.size() - r;
	rotate(x.begin(), x.begin() + r, x.end());
	rotate(y.begin(), y.begin() + r, y.end());
	for (char m: seq) {
		if (m == 'K' && b[i][j] != '*' && b[i][j] != '#')
			s += b[i][j];
		else if (m != 'K' && valid(i, j, y[map[m]], x[map[m]])) {
			i += y[map[m]];
			j += x[map[m]];
		}
	}
	return s;
}

int main() {
	freopen("keyboard.in", "r", stdin);
	freopen("output.out", "w", stdout);

	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		int r, s;
		string seq;
		cin >> r >> s;
		cout << i << endl;
		while (s--) {
			cin >> seq;
			cout << keyboard(r, seq) << endl;
		}
	}

	return 0;
}