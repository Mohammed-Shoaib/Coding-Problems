// Problem Code: 1330D

#include <iostream>

using namespace std;

int sequences(int d, int m) {
	long long cnt, n, choices;
	cnt = n = 1;
	
	while (n <= d) {
		choices = (min(n << 1, d + 1LL) - n + 1) % m;
		cnt = (cnt * choices) % m;
		n <<= 1;
	}
	
	return (cnt - 1 + m) % m;
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		int d, m;
		cin >> d >> m;
		cout << sequences(d, m) << endl;
	}
	return 0;
}