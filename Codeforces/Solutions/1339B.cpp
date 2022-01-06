// Problem Code: 1339B

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> adjacent_differences(int n, vector<int>& a) {
	vector<int> b(n);
	sort(a.begin(), a.end());

	for (int i = n / 2, j = 1; j <= n; j++) {
		b[j - 1] = a[i];
		i += (j & 1) ? -j : j;
	}
	
	return b;
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		vector<int> b, a(n);
		for (int i = 0; i < n; i++)
			cin >> a[i];
		b = adjacent_differences(n, a);
		for (int i = 0; i < n; i++)
			cout << b[i] << " ";
		cout << endl;
	}
	return 0;
}