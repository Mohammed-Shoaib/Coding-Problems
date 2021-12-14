// Problem Code: 1296B

#include <iostream>

using namespace std;

int food_buying(int s) {
	int b = 0, n = 1;
	while (n * 10 <= s)
		n *= 10;
	while (s) {
		b += n;
		s -= n - n / 10;
		while (n > s)
			n /= 10;
	}
	return b;
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		int s;
		cin >> s;
		cout << food_buying(s) << endl;
	}
	return 0;
}