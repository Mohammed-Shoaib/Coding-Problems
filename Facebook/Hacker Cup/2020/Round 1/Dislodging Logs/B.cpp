#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

long long dislodging_logs(int N, int M, vector<int>& P, vector<int>& Q) {
	int mid, low = 1, high = 1e9;
	
	// preprocess
	sort(P.begin(), P.end());
	sort(Q.begin(), Q.end());
	
	// helper function
	auto good = [&](int x) {
		for (int i = 0, r = 0; i < N; i++) {
			int l = r;
			while (r < M && min(abs(P[i] - Q[l]), abs(P[i] - Q[r])) + Q[r] - Q[l] <= x)
				r++;
			if (r == M)
				return true;
		}
		return false;
	};
	
	// binary search
	while (low < high) {
		mid = low + (high - low) / 2;
		if (good(mid))
			high = mid;
		else
			low = mid + 1;
	}
	
	return high;
}

void read_sequence(int K, vector<int>& arr) {
	long long A, B, C, D;
	for (int i = 0; i < K; i++)
		cin >> arr[i];
	cin >> A >> B >> C >> D;
	for (int i = K; i < arr.size(); i++)
		arr[i] = (A * arr[i - 2] + B * arr[i - 1] + C) % D + 1;
}

int main() {
	int T;
	cin >> T;
	for (int x = 1; x <= T; x++) {
		int N, M, K, S;
		cin >> N >> M >> K >> S;
		vector<int> P(N), Q(M);
		read_sequence(K, P);
		read_sequence(K, Q);
		cout << "Case #" << x << ": " << dislodging_logs(N, M, P, Q) << endl;
	}
	return 0;
}