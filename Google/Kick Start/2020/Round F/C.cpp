#include <iostream>
#include <vector>
#include <utility>

using namespace std;

int painters_duel(int S, int C, pair<int, int>& A, pair<int, int>& B, vector<pair<int, int>>& D) {
	if (C == 2 || C == 1 && D[0].first == 2 && D[0].second == 2)
		return 0;
	else if (B.first == 2 && B.second == 2)
		return -1;
	else if (C == 1 || A.first == 2 && A.second == 2)
		return 1;
	else
		return 2;
}

int main() {
	int T;
	cin >> T;
	for (int x = 1; x <= T; x++) {
		int S, C;
		pair<int, int> A, B;
		cin >> S >> A.first >> A.second >> B.first >> B.second >> C;
		vector<pair<int, int>> D(C);
		
		for (int i = 0; i < C; i++)
			cin >> D[i].first >> D[i].second;
		
		cout << "Case #" << x << ": " << painters_duel(S, C, A, B, D) << endl;
	}
	return 0;
}