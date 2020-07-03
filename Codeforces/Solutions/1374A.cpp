// Problem Code: 1374A

#include <iostream>

using namespace std;

int required_remainder(int x, int y, int n) {
	int k = x * (n / x) + y;
	if (k > n)
		k -= x;
	return k;
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		int x, y, n;
		cin >> x >> y >> n;
		cout << required_remainder(x, y, n) << endl;
	}
	return 0;
}