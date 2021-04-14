#include <iostream>
#include <cmath>
#include <string>
#include <utility>
#include <unordered_map>

using namespace std;

void overexcited_fan(int X, int Y, string& M) {
	pair<int, int> pos = {0, 0};
	unordered_map<char, pair<int, int>> mp = {
		{'N', {0, 1}}, {'S', {0, -1}}, {'E', {1, 0}}, {'W', {-1, 0}}
	};

	for (int i = 0; i < M.length(); i++) {
		X += mp[M[i]].first;
		Y += mp[M[i]].second;
		int t = abs(X) + abs(Y);
		if (t <= i + 1) {
			cout << i + 1 << endl;
			return;
		}
	}

	cout << "IMPOSSIBLE" << endl;
}

int main() {
	int T;
	cin >> T;
	for (int x = 1; x <= T; x++) {
		int X, Y;
		string M;
		cin >> X >> Y >> M;
		cout << "Case #" << x << ": ";
		overexcited_fan(X, Y, M);
	}
	return 0;
}