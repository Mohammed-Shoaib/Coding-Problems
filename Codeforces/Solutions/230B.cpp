// Problem Code: 230B
 
#include <iostream>
#include <cmath>
#include <set>
#include <vector>

using namespace std;

void t_primes(int n, vector<int64_t>& x) {
	int mxN = 1e6;
	
	set<int64_t> primes;
	vector<bool> is_prime(mxN + 1, true);
	
	// sieve of eratosthenes
	is_prime[0] = is_prime[1] = false;
	for (int i = 2; i * i <= mxN; i++) {
		if (!is_prime[i])
			continue;
		for (int j = i * i; j <= mxN; j += i)
			is_prime[j] = false;
	}
	
	// list of primes
	for (int i = 2; i <= mxN; i++)
		if (is_prime[i])
			primes.insert(i);
	
	for (int i = 0; i < n; i++) {
		int64_t y = sqrt(x[i]);
		if (y > 1 && y * y == x[i] && primes.count(y))
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}	
}

int main() {
	int n;
	cin >> n;
	vector<int64_t> x(n);
	for (int i = 0; i < n; i++)
		cin >> x[i];
	t_primes(n, x);
	return 0;
}