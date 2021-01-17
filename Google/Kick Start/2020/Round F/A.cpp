#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

void atm_queue(int N, int X, vector<int>& A) {
	vector<pair<int, int>> order(N);
	for (int i = 0; i < N; i++)
		order[i] = {(A[i] + X - 1) / X, i};
	sort(order.begin(), order.end());
	for (int i = 0; i < N; i++)
		cout << order[i].second + 1 << " ";
	cout << endl;
}

int main() {
	int T;
	cin >> T;
	for (int x = 1; x <= T; x++) {
		int N, X;
		cin >> N >> X;
		vector<int> A(N);
		for (int i = 0; i < N; i++)
			cin >> A[i];
		cout << "Case #" << x << ": ";
		atm_queue(N, X, A);
	}
	return 0;
}