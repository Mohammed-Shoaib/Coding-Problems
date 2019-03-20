#include <iostream>
#include <cstdio>

using namespace std;

int total_terms(long long n) {
	return 1 + (n - 1) / 3;
}

long long rocket(long long n) {
	return total_terms(n) * (1 + n) - n;
}

int main() {
	freopen("rocket.in", "r", stdin);
	freopen("output.out", "w", stdout);
	long long n;
	while (cin >> n && n)
		cout << rocket(n) << endl;
	return 0;
}