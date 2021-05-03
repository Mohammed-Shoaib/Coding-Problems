#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

bool is_prime(int64_t n) {
	// base cases
	if (n <= 1)
		return false;
	else if (n == 2 || n == 3)
		return true;
	else if (n % 2 == 0 || n % 3 == 0)
		return false;
	
	// primes are of the form 6k - 1 or 6k + 1
	for (int i = 5; i * i <= n; i += 6)
		if (n % i == 0 || n % (i + 2) == 0)
			return false;
	
	return true;
}

int64_t next_prime(int64_t p) {
	while (!is_prime(++p));
	return p;
}

int64_t prev_prime(int64_t p) {
	while (!is_prime(--p));
	return p;
}

int64_t consecutive_primes(int64_t Z) {
	int64_t q = next_prime(sqrt(Z)), p = prev_prime(q);
	if (p * q > Z)
		q = prev_prime(p);
	return p * q;
}

int main() {
	int T;
	cin >> T;
	for (int x = 1; x <= T; x++) {
		int64_t Z;
		cin >> Z;
		cout << "Case #" << x << ": " << consecutive_primes(Z) << endl;
	}
	return 0;
}