#include <iostream>
#include <vector>

using namespace std;

int64_t prime_time(int M, vector<int64_t>& P, vector<int64_t>& N) {
	int64_t score, max_sum, limit;
	score = max_sum = 0;
	limit = 30'000;
	
	for (int i = 0; i < M; i++)
		max_sum += P[i] * N[i];
	
	for (int x = 2; x < max_sum && x <= limit; x++) {
		int64_t sum = x, prod = max_sum - x;
		for (int i = 0; i < M; i++)
			for (int j = 0; j < N[i] && prod % P[i] == 0; j++) {
				sum -= P[i];
				prod /= P[i];
			}
		if (sum == 0 && prod == 1)
			score = max(score, max_sum - x);
	}
	
	return score;
}

int main() {
	int T;
	cin >> T;
	for (int x = 1; x <= T; x++) {
		int M;
		cin >> M;
		vector<int64_t> P(M), N(M);
		for (int i = 0; i < M; i++)
			cin >> P[i] >> N[i];
		cout << "Case #" << x << ": " << prime_time(M, P, N) << endl;
	}
	return 0;
}