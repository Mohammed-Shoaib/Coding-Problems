#include <iostream>
#include <string>
#include <vector>

using namespace std;

void oversized_pancake_flipper(int K, string& S) {
	int flips, bit, N = S.length();
	flips = bit = 0;
	vector<bool> lazy(N + 1);
	
	for (int i = 0; i < N - K + 1; i++) {
		bit ^= lazy[i];
		if (bit && S[i] == '-' || bit == 0 && S[i] == '+')
			continue;
		flips++;
		bit ^= 1;
		lazy[i + K] = true;
	}
	
	for (int i = N - K + 1; i < N; i++) {
		bit ^= lazy[i];
		if (bit && S[i] == '+' || bit == 0 && S[i] == '-') {
			cout << "IMPOSSIBLE" << endl;
			return;
		}
	}
	
	cout << flips << endl;
}

int main() {
	int T;
	cin >> T;
	for (int x = 1; x <= T; x++) {
		int K;
		string S;
		cin >> S >> K;
		cout << "Case #" << x << ": ";
		oversized_pancake_flipper(K, S);
	}
	return 0;
}