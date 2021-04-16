#include <iostream>
#include <string>
#include <vector>
#include <iterator>
#include <algorithm>

using namespace std;

void hacked_exam(int N, int Q, vector<int>& S, vector<string>& A) {
	for (int i = 0; i < N; i++) {
		if (2 * S[i] >= Q)
			continue;
		S[i] = Q - S[i];
		for (int j = 0; j < Q; j++) {
			if (A[i][j] == 'T')
				A[i][j] = 'F';
			else
				A[i][j] = 'T';
		}
	}
	int pos = distance(S.begin(), max_element(S.begin(), S.end()));
	
	cout << A[pos] << " " << S[pos] << "/1" << endl;
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