// Problem Code: 1270C

#include <iostream>
#include <vector>
#include <numeric>
#include <functional>

using namespace std;

void make_good(int n, vector<int>& a) {
	long long sum = accumulate(a.begin(), a.end(), 0LL);
	int x = accumulate(a.begin(), a.end(), 0, bit_xor<int>());
	cout << 2 << endl;
	cout << x << " " << sum + x << endl;
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		vector<int> a(n);
		for (int i = 0; i < n; i++)
			cin >> a[i];
		make_good(n, a);
	}
	return 0;
}