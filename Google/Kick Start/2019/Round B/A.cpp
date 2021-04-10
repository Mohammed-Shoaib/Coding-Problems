#include <iostream>
#include <vector>

using namespace std;

int building_palindromes(int N, int Q, string& S) {
	int cnt = 0, M = 26;
	vector<vector<int>> prefix(N + 1, vector<int>(M));
	
	for (int i = 0; i < N; i++) {
		prefix[i + 1] = prefix[i];
		prefix[i + 1][S[i] - 'A'] ^= 1;
	}
	
	while (Q--) {
		int L, R;
		cin >> L >> R;
		int odd = 0;
		for (int i = 0; i < M; i++)
			odd += prefix[R][i] ^ prefix[L - 1][i];
		cnt += odd <= 1;
	}
	
	return cnt;
}

int main() {
	int T;
	cin >> T;
	for (int x = 1; x <= T; x++) {
		int N, Q;
		string S;
		cin >> N >> Q >> S;
		cout << "Case #" << x << ": " << building_palindromes(N, Q, S) << endl;
	}
	return 0;
}