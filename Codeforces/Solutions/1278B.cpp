// Problem Code: 1278B

#include <iostream>
#include <cmath>

using namespace std;

int sum(int n) {
	return n * (n + 1) / 2;
}

int equal(int a, int b) {
	int n, d;
	n = 0;
	d = abs(a - b);
	while (sum(n) < d || (sum(n) + d) & 1)
		n++;
	return n;
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		int a, b;
		cin >> a >> b;
		cout << equal(a, b) << endl;
	}
	return 0;
}