// Problem Code: 1282A

#include <iostream>
#include <algorithm>

using namespace std;

int unavailable(int a, int b, int c, int r) {
	int left, right;
	if (a > b)
		swap(a, b);
	left = max(a, c - r);
	right = min(b, c + r);
	return (b - a) - max(0, right - left);
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		int a, b, c, r;
		cin >> a >> b >> c >> r;
		cout << unavailable(a, b, c, r) << endl;
	}
	return 0;
}