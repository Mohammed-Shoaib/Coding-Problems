// Problem Code: 1108A

#include <iostream>
#include <utility>

using namespace std;

pair<int, int> twoDistinctPoints(int l1, int r1, int l2, int r2) {
	return (l1 != r2) ? make_pair(l1, r2) : make_pair(l1, l2);
}

int main() {
	int q;
	cin >> q;
	while (q--) {
		int l1, r1, l2, r2;
		pair<int, int> p;
		cin >> l1 >> r1 >> l2 >> r2;
		p = twoDistinctPoints(l1, r1, l2, r2);
		cout << p.first << " " << p.second << endl;
	}
	return 0;
}