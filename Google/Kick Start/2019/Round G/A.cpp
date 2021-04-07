#include <iostream>
#include <vector>

using namespace std;

int64_t book_reading(int N, int M, int Q, vector<int>& P, vector<int>& R) {
	int64_t pages = 0;
	vector<int> seen(N + 1);
	
	for (int& x: P)
		seen[x]++;
	
	for (int i = 1; i <= N; i++)
		for (int j = i << 1; j <= N; j += i)
			seen[i] += seen[j];
	
	for (int& x: R) {
		pages += N / x;
		pages -= seen[x];
	}
	
	return pages;
}

int main() {
	int T;
	cin >> T;
	for (int x = 1; x <= T; x++) {
		int N, M, Q;
		cin >> N >> M >> Q;
		vector<int> P(M), R(Q);
		for (int i = 0; i < M; i++)
			cin >> P[i];
		for (int i = 0; i < Q; i++)
			cin >> R[i];
		cout << "Case #" << x << ": " << book_reading(N, M, Q, P, R) << endl;
	}
	return 0;
}