// Problem Code: 1373E

#include <iostream>
#include <limits>
#include <algorithm>

using namespace std;

long long construct(int len) {
	if (len <= 8)
		return len;
	len -= 8;
	long long prefix = len % 9;
	len -= len % 9;
	while (len) {
		prefix = 10 * prefix + 9;
		len -= 9;
	}
	prefix = 10 * prefix + 8;
	return prefix;
}

long long sum_of_digits(int n, int k) {
	long long min_x, x, inf, tens;
	min_x = inf = numeric_limits<long long>::max();
	tens = 10;
	for (int m = 0; 9 * m <= n; m++, tens *= 10)
		for (int d = 0; d <= 9; d++) {
			int sum, no_carry, len;
			sum = 0;
			no_carry = min(10 - d, k + 1);
			for (int i = 0; i <= k; i++)
				sum += (d + i) % 10;
			len = n - sum - 9 * m * no_carry - (k + 1 - no_carry);
			if (len >= 0 && len % (k + 1) == 0) {
				len /= (k + 1);
				x = tens * (construct(len) + 1) - 10 + d;
				min_x = min(x, min_x);
			}
		}
	return (min_x == inf) ? -1 : min_x;
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n, k;
		cin >> n >> k;
		cout << sum_of_digits(n, k) << endl;
	}
	return 0;
}