#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int mod = 1e9 + 7;

int perimetric(int N, int W, vector<int>& L, vector<int>& H) {
	vector<long long> P(N);
	P[0] = 2 * (W + H[0]);
	long long prod = P[0] % mod;

	for (int i = 1; i < N; i++) {
		// initialization
		int j = i - 1, max_h = 0;
		P[i] = P[i - 1] + 2 * (W + H[i]);
		
		// try to find a higher room
		while (j > 0 && L[j] + W >= L[i] && H[j] <= H[i])
			max_h = max(H[j--], max_h);
		
		// remove overlapping width
		if (L[i - 1] + W >= L[i])
			P[i] -= 2 * (L[i - 1] + W - L[i]);
		
		// remove overlapping height
		if (L[j] + W >= L[i])
			max_h = max(H[j], max_h);
		P[i] -= 2 * min(H[i], max_h);

		// compute product
		P[i] %= mod;
		if (P[i] < 0)
			P[i] += mod;
		prod = (prod * P[i]) % mod;
	}
	
	return prod;
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
		int N, K, W;
		cin >> N >> K >> W;
		vector<int> L(N), H(N);
		read_sequence(K, L);
		read_sequence(K, H);
		cout << "Case #" << x << ": " << perimetric(N, W, L, H) << endl;
	}
	return 0;
}