// Problem Code: 318A
 
#include <iostream>

using namespace std;

int64_t even_odds(int64_t n, int64_t k) {
	int64_t x = (n + 1) / 2;
	if (k <= x)
		return 2 * k - 1;
	else
		return 2 * (k - x);
}

int main() {
	int64_t n, k;
	cin >> n >> k;
	cout << even_odds(n, k);
	return 0;
}