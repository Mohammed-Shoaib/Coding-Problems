#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

void reversort_engineering(int N, int C) {
	// base case
	if (C < N - 1 || C >= N * (N + 1) / 2) {
		cout << "IMPOSSIBLE" << endl;
		return;
	}
	
	vector<int> L(N);
	C -= N - 1;
	iota(L.begin(), L.end(), 1);
	
	// construct the solution
	for (int i = N - 2; i >= 0; i--) {
		int cost = min(N - i - 1, C);
		C -= cost;
		reverse(L.begin() + i, L.begin() + i + 1 + cost);
	}
	
	for (int& x: L)
		cout << x << " ";
	cout << endl;
}

int main() {
	int T;
	cin >> T;
	for (int x = 1; x <= T; x++) {
		int N, C;
		cin >> N >> C;
		cout << "Case #" << x << ": ";
		reversort_engineering(N, C);
	}
	return 0;
}