// Problem Code: 1269B

#include <iostream>
#include <vector>
#include <limits>
#include <algorithm>

using namespace std;

int modulo_equality(int n, int m, vector<int>& a, vector<int>& b) {
	int i, j, d, min_d = numeric_limits<int>::max();
	sort(a.begin(), a.end());
	sort(b.begin(), b.end());

	for (int k = 0; k < n; k++) {
		d = (m - a[0] + b[k]) % m;
		for (i = 0, j = k; i < n; i++, j = (j + 1) % n)
			if ((a[i] + d) % m != b[j])
				break;
		if (i == n)
			min_d = min(d, min_d);
	}
	
	return min_d;
}

int main() {
	int n, m;
	cin >> n >> m;
	vector<int> a(n), b(n);
	for (int i = 0; i < n; i++)
		cin >> a[i];
	for (int i = 0; i < n; i++)
		cin >> b[i];
	cout << modulo_equality(n, m, a, b);
	return 0;
}