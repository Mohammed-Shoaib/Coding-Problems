// Problem Code: 1080B

#include <iostream>

using namespace std;

int F(int x) {
	if (x & 1)
		return F(x - 1) - x;
	else
		return x / 2;
}

int query(int l, int r) {
	return F(r) - F(l - 1);
}

int main() {
	int q, l, r;
	cin >> q;
	while(q--) {
		cin >> l >> r;
		cout << query(l, r) << endl;
	}
	return 0;
}