#include <iostream>
#include <string>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

int cheating_detection(int N, int K, vector<string>& A) {
	int Q = K / 10;
	vector<int> hard(N);
	pair<double, int> cheater;
	vector<pair<int, int>> scores(K), easy(N);
	
	// sort questions by level of difficulty
	for (int i = 0; i < N; i++)
		for (int j = 0; j < K; j++) {
			scores[j].first += A[i][j] - '0';
			scores[j].second = j;
		}
	sort(scores.begin(), scores.end());
	
	// sort players by level of skill
	for (int i = 0; i < K; i++)
		for (int j = 0; j < N; j++)
			if (A[j][scores[i].second] == '1') {
				easy[j].first += K - i;
				easy[j].second = j;
			}
	sort(easy.begin(), easy.end());
	
	// compute performance for hard questions
	for (int i = 0; i < Q; i++)
		for (int j = 0; j < N; j++)
			if (A[j][scores[i].second] == '1')
				hard[j] += K - i;
	
	// find the cheater by discrepancy in skill
	for (int i = 0; i < N; i++) {
		double score = 0;
		if (i > 0)
			score += abs(hard[easy[i].second] - hard[easy[i - 1].second]);
		if (i + 1 < N)
			score += abs(hard[easy[i].second] - hard[easy[i + 1].second]);
		score /= 1 + (i > 0 && i + 1 < N);
		cheater = max({score, easy[i].second}, cheater);
	}
	
	return cheater.second + 1;
}

int main() {
	int T, P;
	cin >> T >> P;
	for (int x = 1; x <= T; x++) {
		int N = 100, K = 10'000;
		vector<string> A(N);
		for (int i = 0; i < N; i++)
			cin >> A[i];
		cout << "Case #" << x << ": " << cheating_detection(N, K, A) << endl;
	}
	return 0;
}