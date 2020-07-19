#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int record_breaker(int N, vector<int>& V) {
	int max_v = -1, cnt = 0;
	for (int i = 0; i + 1 < N; i++) {
		cnt += (V[i] > max_v && V[i] > V[i + 1]);
		max_v = max(V[i], max_v);
	}
	cnt += (V.back() > max_v);
	return cnt;
}

int main() {
	int T;
	cin >> T;
	for (int x = 1; x <= T; x++) {
		int N;
		cin >> N;
		vector<int> V(N);
		for (int i = 0; i < N; i++)
			cin >> V[i];
		cout << "Case #" << x << ": " << record_breaker(N, V) << endl;
	}
	return 0;
}