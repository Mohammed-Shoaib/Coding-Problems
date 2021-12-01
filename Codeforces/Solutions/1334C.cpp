// Problem Code: 1334C

#include <iostream>
#include <vector>
#include <limits>
#include <algorithm>

using namespace std;

long long circle_of_monsters(int n, vector<long long>& a, vector<long long>& b) {
	long long shots, mn, damage;
	shots = 0;
	mn = numeric_limits<long long>::max();

	for (int i = 0; i < n; i++) {
		int next = (i + 1) % n;
		damage = min(a[next], b[i]);	// a - max(0, a - b) => min(a, b)
		mn = min(damage, mn);
		shots += a[next] - damage;		// max(0, a - b) => a - min(a, b)
	}
	shots += mn;						// [a - min(a, b)] + min(a, b) => a

	return shots;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int T;
	cin >> T;
	while (T--) {
		int n;
		cin >> n;
		vector<long long> a(n), b(n);
		for (int i = 0; i < n; i++)
			cin >> a[i] >> b[i];
		cout << circle_of_monsters(n, a, b) << '\n';
	}
	return 0;
}