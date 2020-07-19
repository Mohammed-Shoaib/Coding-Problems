#include <iostream>
#include <iomanip>
#include <vector>
#include <functional>
#include <unordered_set>

using namespace std;

double beauty_of_tree(int N, int A, int B, vector<int>& parent) {
	double expected = 0;
	unordered_set<int> seen;

	function<void(int, int)> beauty = [&](int s, int steps) {
		seen.insert(s);
		for (int i = 0; i < steps; i++) {
			if (s == parent[s])
				return;
			s = parent[s];
		}
		beauty(s, steps);
	};

	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++) {
			seen.clear();
			beauty(i, A);
			beauty(j, B);
			expected += seen.size();
		}
	expected /= (long long) N * N;
	
	return expected;
}

int main() {
	int T;
	cin >> T;
	for (int x = 1; x <= T; x++) {
		int N, A, B;
		cin >> N >> A >> B;
		vector<int> parent(N);
		for (int i = 1; i < N; i++) {
			cin >> parent[i];
			parent[i]--;
		}
		cout << "Case #" << x << ": " << fixed << setprecision(6) << beauty_of_tree(N, A, B, parent) << endl;
	}
	return 0;
}