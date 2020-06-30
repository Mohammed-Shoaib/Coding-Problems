// Problem Code: abc172_e

#include <iostream>
#include <numeric>
#include <vector>
#include <functional>

using namespace std;

int inverse(long long a, int m) {
	// fermat's little theorem
	int x = 1, n = m - 2;
	while (n) {
		if (n & 1)
			x = (x * a) % m;
		a = (a * a) % m;
		n >>= 1;
	}
	return x;
}

int neq(int N, int M) {
	int mod = 1e9 + 7;
	vector<long long> fact(M + 1), inv_fact(M + 1);

	// preprocess the factorials and inverse factorials
	fact[0] = 1;
	for (int i = 1; i <= M; i++)
		fact[i] = (i * fact[i - 1]) % mod;
	inv_fact[M] = inverse(fact[M], mod);
	for (int i = M - 1; i >= 0; i--)
		inv_fact[i] = ((i + 1) * inv_fact[i + 1]) % mod;
	
	// helper function to compute n choose r
	auto nCr = [&](int n, int r) {
		int den = (inv_fact[r] * inv_fact[n - r]) % mod;
		return (fact[n] * den) % mod;
	};

	int ways_b = 0, neg = 1;
	long long ways_a = (nCr(M, N) * fact[N]) % mod;

	for (int j = 0; j <= N; j++) {
		int ways = (nCr(N, j) * nCr(M - j, N - j)) % mod;
		ways = (ways * fact[N - j]) % mod;
		ways = (neg * ways + mod) % mod;
		ways_b = (ways_b + ways) % mod;
		neg *= -1;
	}

	return (ways_a * ways_b) % mod;
}

int main() {
	int N, M;
	cin >> N >> M;
	cout << neq(N, M);
	return 0;
}