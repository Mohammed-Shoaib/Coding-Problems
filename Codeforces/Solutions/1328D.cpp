// Problem Code: 1328D

#include <iostream>
#include <vector>

using namespace std;

void carousel(int n, vector<int>& t) {
	int k, pos;
	k = 1;
	pos = -1;
	vector<int> col(n, 1);
	
	for (int i = 1; i < n; i++) {
		if (t[i] != t[i - 1])	// all animals are not the same
			k = 2;
		else
			pos = i;			// keep track of same adjacent pair
	}

	if (k > 1) {
		for (int i = 0; i < n; i++)		// [1, 2, 1, 2, ...]
			col[i] += (i & 1);
		if ((n & 1) && t[0] != t[n - 1]){	// length is odd with first != last
			if (pos == -1)
				k = col[n - 1] = 3;
			else {
				col[pos] = col[pos - 1];	// fix coloring
				for (int i = pos + 1; i < n; i++)
					col[i] = 1 + col[i - 1] % 2;
			}
		}
	}
	
	cout << k << endl;
	for (int i = 0; i < n; i++)
		cout << col[i] << " ";
	cout << endl;
}

int main() {
	int q;
	cin >> q;
	while (q--) {
		int n;
		cin >> n;
		vector<int> t(n);
		for (int i = 0; i < n; i++)
			cin >> t[i];
		carousel(n, t);
	}
	return 0;
}