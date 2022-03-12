// Problem Code: 996B

#include <iostream>
#include <vector>
#include <limits>

using namespace std;

int world_cup(int n, vector<int>& a) {
	int t, pos, mn = numeric_limits<int>::max();
	for (int i = 0; i < n; i++) {
		t = max(0, (a[i] - i + n - 1) / n);
		if (t < mn) {
			mn = t;
			pos = i + 1;
		}
	}
	return pos;
}

int main() {
	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++)
		cin >> a[i];
	cout << world_cup(n, a);
	return 0;
}