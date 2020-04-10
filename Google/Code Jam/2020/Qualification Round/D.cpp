#include <iostream>
#include <cassert>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

int query(int x) {
	int res;
	cout << x + 1 << endl;
	cin >> res;
	return res;
}

void esab_atad(int B) {
	vector<int> b(B);
	int same, diff, q = 1;
	same = diff = -1;

	// helper function
	function<void()> fluctuate = [&]() {
		if (same != -1) {
			if (b[same] != query(same))		// complementation
				for (int& x: b)
					x ^= 1;
			q++;
		}
		if (diff != -1) {
			if (b[diff] != query(diff))		// reversal
				reverse(b.begin(), b.end());
			q++;
		}
		if (q % 2 == 0) {	// waste query
			query(0);
			q++;
		}
	};

	// query bits
	for (int i = 0, j = B - 1; i < j; i++, j--) {
		// quantum fluctuation
		if (q % 10 == 1)
			fluctuate();
		b[i] = query(i);
		b[j] = query(j);
		if (same == -1 && b[i] == b[j])
			same = i;
		if (diff == -1 && b[i] != b[j])
			diff = i;
		q += 2;
	}

	for (int i = 0; i < B; i++)
		cout << b[i];
	cout << endl;
}

int main() {
	int T, B;
	cin >> T >> B;
	for (int x = 1; x <= T; x++) {
		char c;
		esab_atad(B);
		cin >> c;
		assert(c == 'Y');
	}
	return 0;
}