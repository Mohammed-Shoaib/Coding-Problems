// Problem Code: 1334B

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int B(int n, int x, vector<int>& a) {
	long long sum, k;
	sum = k = 0;
	sort(a.rbegin(), a.rend());
	while (k < n) {
		sum += a[k++];
		if (sum < x * k)
			return k - 1;
	}
	return k;
}

int main() {
	int T;
	cin >> T;
	while (T--) {
		int n, x;
		cin >> n >> x;
		vector<int> a(n);
		for (int i = 0; i < n; i++)
			cin >> a[i];
		cout << B(n, x, a) << endl;
	}
	return 0;
}