// Problem Code: abc172_d

#include <iostream>

using namespace std;

long long sum_of_divisors(int N) {
	long long res = 0;
	for (int i = 1; i <= N; i++) {
		long long f = N / i;
		res += i * f * (f + 1) / 2;
	}
	return res;
}

int main() {
	int N;
	cin >> N;
	cout << sum_of_divisors(N);
	return 0;
}