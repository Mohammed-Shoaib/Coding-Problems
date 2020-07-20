#include <iostream>
#include <vector>
#include <limits>

using namespace std;

// passes test set 1
int locked_doors(int N, int S, int K, vector<int>& D) {
	int l, r;
	l = r = S;
	while (K--) {
		if (D[l] > D[r])
			S = ++r;
		else
			S = l--;
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
		D[0] = D[N] = numeric_limits<int>::max();
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