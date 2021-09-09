// Problem Code: 1082A

#include <iostream>
#include <cmath>
#include <limits>

using namespace std;

const int INF = numeric_limits<int>::max();

int vasyaAndBook(int n, int x, int y, int d) {
	if (abs(y - x) % d == 0)
		return abs(y - x) / d;

	int d1, d2, presses;
	d1 = d2 = INF;

	if ((y - 1) % d == 0) {
		d1 = y / d;
		d1 += (x + d - 1) / d;
	}
	if((n - y) % d == 0) {
		d2 = (n - y) / d;
		d2 += (n - x + d - 1) / d;
	}

	presses = min(d1, d2);
	if (presses == INF)
		presses = -1;
	return presses;
}

int main() {
	int T, n, x, y, d;
	cin >> T;
	while (T--) {
		cin >> n >> x >> y >> d;
		cout << vasyaAndBook(n, x, y, d) << endl;
	}
	return 0;
}