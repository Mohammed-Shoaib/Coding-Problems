#include <iostream>
#include <cmath>
#include <string>

using namespace std;

int k_goodness_string(int N, int K, string& S) {
	int score = 0;
	for (int i = 0; i < N / 2; i++)
		score += S[i] != S[N - i - 1];
	return abs(score - K);
}

int main() {
	int T;
	cin >> T;
	for (int x = 1; x <= T; x++) {
		int N, K;
		string S;
		cin >> N >> K >> S;
		cout << "Case #" << x << ": " << k_goodness_string(N, K, S) << endl;
	}
	return 0;
}