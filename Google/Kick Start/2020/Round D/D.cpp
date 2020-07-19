#include <iostream>
#include <vector>
#include <limits>

using namespace std;

int locked_doors(int N, int S, int K, vector<int> D) {
	int l = S - 1, r = S;
	const int INF = numeric_limits<int>::max();
	D[0] = D[N] = INF;
	
	while (--K) {
		if (D[l] > D[r]) {
			S = r + 1;
			D[r++] = INF;
		} else {
			S = l;
			D[l--] = INF;
		}
	}
	
	return S;
}

int main() {
	int T;
	cin >> T;
	for (int x = 1; x <= T; x++) {
		int N, Q;
		cin >> N >> Q;
		vector<int> D(N + 1);
		for (int i = 1; i < N; i++)
			cin >> D[i];
		cout << "Case #" << x << ":";
		while (Q--) {
			int S, K;
			cin >> S >> K;
			cout << " " << locked_doors(N, S, K, D);
		}
		cout << endl;
	}
	return 0;
}