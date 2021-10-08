// Problem Code: 1271E

#include <iostream>

using namespace std;

long long common_number(long long n, long long k) {
	long long odd, even, x;

	// Calculate the maximum odd value
	x = 1;
	while (x <= k)
		x <<= 1;
	x >>= 1;
	odd = (n - (k - x)) / max(1LL, x);
	odd -= (odd + 1) % 2;

	// Calculate the maximum even value
	x = 1;
	while (x <= k + 1)
		x <<= 1;
	x >>= 2;
	even = (n - (k - 2 * x + 1)) / max(1LL, x);
	even -= even % 2;
	
	return max(odd, even);
}

int main() {
	long long n, k;
	cin >> n >> k;
	cout << common_number(n, k);
	return 0;
}