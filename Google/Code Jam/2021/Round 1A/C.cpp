#include <iostream>
#include <string>
#include <vector>
#include <numeric>

using namespace std;

void hacked_exam(int N, int Q, vector<int>& S, vector<string>& A) {
	int max_score = 0, limit = 1 << Q;
	vector<int> consistent;
	string hacked(Q, 'F');
	
	for (int b = 0; b < limit; b++) {
		bool ok = true;
		string answer(Q, 'F');
		
		for (int j = 0; j < Q; j++)
			if ((b >> j) & 1)
				answer[j] = 'T';
		
		for (int i = 0; i < N && ok; i++) {
			int score = 0;
			for (int j = 0; j < Q; j++)
				score += A[i][j] == answer[j];
			ok &= score == S[i];
		}
		
		if (ok)
			consistent.push_back(b);
	}
	
	for (int b = 0; b < limit; b++) {
		int score = 0;
		for (int& answer: consistent)
			for (int j = 0; j < Q; j++)
				if (((b >> j) & 1) == ((answer >> j) & 1))
					score++;
		if (score <= max_score)
			continue;
		
		max_score = score;
		hacked = string(Q, 'F');
		for (int j = 0; j < Q; j++)
			if ((b >> j) & 1)
				hacked[j] = 'T';
	}
	
	int x, y, g;
	g = gcd(max_score, (int) consistent.size());
	if (g) {
		x = max_score / g;
		y = consistent.size() / g;
	} else {
		x = max_score;
		y = consistent.size();
	}
	
	cout << hacked << " " << x << "/" << y << endl;
}

int main() {
	int T;
	cin >> T;
	for (int x = 1; x <= T; x++) {
		int N, Q;
		cin >> N >> Q;
		vector<int> S(N);
		vector<string> A(N);
		for (int i = 0; i < N; i++)
			cin >> A[i] >> S[i];
		cout << "Case #" << x << ": ";
		hacked_exam(N, Q, S, A);
	}
	return 0;
}