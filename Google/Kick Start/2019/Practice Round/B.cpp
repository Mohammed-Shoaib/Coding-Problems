#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int mural(int N, string& S) {
	int sum, max_sum;
	sum = max_sum = 0;
	
	for (int i = 0; i < N; i++) {
		int j = i - (N + 1) / 2;
		if (j >= 0)
			sum -= S[j] - '0';
		sum += S[i] - '0';
		max_sum = max(sum, max_sum);
	}
	
	return max_sum;
}

int main() {
	int T;
	cin >> T;
	for (int x = 1; x <= T; x++) {
		int N;
		string S;
		cin >> N >> S;
		cout << "Case #" << x << ": " << mural(N, S) << endl;
	}
	return 0;
}