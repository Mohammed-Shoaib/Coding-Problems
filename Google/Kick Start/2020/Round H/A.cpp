#include <iostream>
#include <algorithm>

using namespace std;

int retype(int N, int K, int S) {
	return K + min(N + K - 2 * S, N);
}

int main() {
	int T;
	cin >> T;
	for (int x = 1; x <= T; x++) {
		int N, K, S;
		cin >> N >> K >> S;
		cout << "Case #" << x << ": " << retype(N, K, S) << endl;
	}
	return 0;
}