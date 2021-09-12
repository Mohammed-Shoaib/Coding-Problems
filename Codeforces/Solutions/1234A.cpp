// Problem Code: 1234A

#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

int equalize(int n, vector<int>& a) {
	int sum = accumulate(a.begin(), a.end(), 0);
	return (sum + n - 1) / n;
}

int main() {
	int q;
	cin >> q;
	while (q--) {
		int n;
		cin >> n;
		vector<int> a(n);
		for (int i = 0; i < n; i++)
			cin >> a[i];
		cout << equalize(n, a) << endl;
	}
	return 0;
}