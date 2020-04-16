#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

void pascal_walk(int N) {
	bool left = true;
	vector<pair<int, int>> walk;
	int r, cnt = 0, max_r = min(30, N);
	N -= max_r;

	// construct using binary representation of N - 30
	for (r = 1; r <= max_r; r++, N >>= 1) {
		walk.emplace_back(r, left ? 1 : r);
		if (N % 2 == 0)
			continue;
		for (int k = 2; k <= r; k++)
			walk.emplace_back(r, left ? k : r - k + 1);
		cnt++;
		left = !left;
	}

	// add required number of 1s
	while (cnt--) {
		walk.emplace_back(r, left ? 1 : r);
		r++;
	}
	
	for (pair<int, int>& pos: walk)
		cout << pos.first << " " << pos.second << endl;
}

int main() {
	int T;
	cin >> T;
	for (int x = 1; x <= T; x++) {
		int N;
		cin >> N;
		cout << "Case #" << x << ": " << endl;
		pascal_walk(N);
	}
	return 0;
}