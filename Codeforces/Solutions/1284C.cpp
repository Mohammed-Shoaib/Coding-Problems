// Problem Code: 1284C

#include <iostream>
#include <vector>

using namespace std;

int permutation_happiness(int n, int m) {
	long long rem, h = 0;
	vector<long long> f(n + 1);
	f[0] = 1;
	for (int i = 1; i <= n; i++)
		f[i] = (i * f[i - 1]) % m;
	for (int i = 1; i <= n; i++) {
		rem = n - i + 1;
		h += rem * ((f[i] * f[rem]) % m);
		h %= m;
	}
	return h;
}

int main() {
	int n, m;
	cin >> n >> m;
	cout << permutation_happiness(n, m);
	return 0;
}