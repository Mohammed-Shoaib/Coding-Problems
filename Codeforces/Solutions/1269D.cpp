// Problem Code: 1269D

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long long domino(int n, vector<int>& a) {
	long long cnt[2] = {};
	for (int i = 0; i < n; i++) {
		cnt[i & 1] += a[i] / 2;
		cnt[!(i & 1)] += (a[i] + 1) / 2;
	}
	return min(cnt[0], cnt[1]);
}

int main() {
	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++)
		cin >> a[i];
	cout << domino(n, a);
	return 0;
}