#include <iostream>
#include <cassert>

using namespace std;

int query(int i, int j, char c) {
	int pos;
	if (c == 'D')
		cout << c << endl;
	else
		cout << c << " " << i << " " << j << endl;
	cin >> pos;
	assert(pos != -1);
	return pos;
}

void minimum_sort(int N) {
	for (int i = 1; i < N; i++) {
		int pos = query(i, N, 'M');
		if (i != pos)
			query(i, pos, 'S');
	}
	query(0, 0, 'D');
}

int main() {
	int T, N;
	cin >> T >> N;
	for (int x = 1; x <= T; x++)
		minimum_sort(N);
	return 0;
}