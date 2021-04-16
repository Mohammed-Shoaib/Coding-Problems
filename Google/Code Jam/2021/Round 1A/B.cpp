#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int prime_time(int M, vector<int>& P, vector<int>& N) {
	int score, max_sum;
	score = max_sum = 0;
	
	for (int i = 0; i < M; i++)
		max_sum += P[i] * N[i];
	
	for (int x = 2; x <= max_sum; x++) {
		int prod = 1, sum = max_sum, num = x;
		for (int i = 0; i < M; i++)
			for (int j = 0; j < N[i] && num % P[i] == 0; j++) {
				sum -= P[i];
				num /= P[i];
				prod *= P[i];
			}
		if (sum == prod)
			score = max(score, sum);
	}
	
	return score;
}

int main() {
	int T;
	cin >> T;
	for (int x = 1; x <= T; x++) {
		int M;
		cin >> M;
		vector<int> P(M), N(M);
		for (int i = 0; i < M; i++)
			cin >> P[i] >> N[i];
		cout << "Case #" << x << ": " << prime_time(M, P, N) << endl;
	}
	return 0;
}