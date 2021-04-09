#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

int training(int N, int P, vector<int>& S) {
	int min_h = numeric_limits<int>::max();
	vector<int> prefix(N + 1);
	
	sort(S.begin(), S.end());
	
	for (int i = 0; i < N; i++)
		prefix[i + 1] = prefix[i] + S[i];
	
	for (int i = P; i <= N; i++) {
		int hours = S[i - 1] * P - prefix[i] + prefix[i - P];
		min_h = min(hours, min_h);
	}
	
	return min_h;
}

int main() {
	int T;
	cin >> T;
	for (int x = 1; x <= T; x++) {
		int N, P;
		cin >> N >> P;
		vector<int> S(N);
		for (int i = 0; i < N; i++)
			cin >> S[i];
		cout << "Case #" << x << ": " << training(N, P, S) << endl;
	}
	return 0;
}