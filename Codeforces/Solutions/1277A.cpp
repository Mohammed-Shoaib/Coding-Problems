// Problem Code: 1277A

#include <iostream>

using namespace std;

int happy_birthday(int n) {
	int b = 0;
	for (int d = 1; d <= 9; d++) {
		long long num = d;
		while (num <= n) {
			b++;
			num = 10 * num + d;
		}
	}
	return b;
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		cout << happy_birthday(n) << endl;
	}
	return 0;
}