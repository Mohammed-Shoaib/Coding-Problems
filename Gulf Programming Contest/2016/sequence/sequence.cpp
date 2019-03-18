#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

string sequence(int n, vector<int> a) {
	int flips = 0;
	for (int i = 2; i < n; i++)
		if ((a[i] - a[i - 1] <= 0 && a[i - 1] - a[i - 2] >= 0) ||
			(a[i] - a[i - 1] >= 0 && a[i - 1] - a[i - 2] <= 0))
			flips++;
	if (flips == 0)
		return "mono";
	else if (flips == 1)
		return "bi";
	else
		return "poly";
}

int main() {
	freopen("sequence.in", "r", stdin);
	freopen("output.out", "w", stdout);

	int k, n;
	k = 1;
	while (cin >> n && n) {
		vector <int> a(n);
		for (int i = 0; i < n; i++)
			cin >> a[i];
		cout << k << " " << sequence(n, a) << endl;
		k++;
	}
	return 0;
}
