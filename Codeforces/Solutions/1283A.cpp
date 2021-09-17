// Problem Code: 1283A

#include <iostream>

using namespace std;

int minutes_left(int h, int m) {
	return (23 - h) * 60 + (60 - m);
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		int h, m;
		cin >> h >> m;
		cout << minutes_left(h, m) << endl;
	}
	return 0;
}