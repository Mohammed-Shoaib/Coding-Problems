// Problem Code: 1335E1

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int three_blocks(int n, vector<int>& a) {
	int max_l, mn, mx;
	max_l = 0;
	mn = *min_element(a.begin(), a.end());
	mx = *max_element(a.begin(), a.end());
	vector<vector<int>> prefix(mx + 1, vector<int>(n + 1));

	// compute prefix sum array
	for (int x = mn; x <= mx; x++)
		for (int i = 0; i < n; i++)
			prefix[x][i + 1] = prefix[x][i] + (a[i] == x);
	
	// brute-force all ranges
	for (int l = 1; l <= n; l++)
		for (int r = l; r <= n; r++) {
			int max_x, max_y;
			max_x = max_y = 0;
			for (int y = mn; y <= mx; y++)
				max_y = max(prefix[y][r] - prefix[y][l - 1], max_y);
			for (int x = mn; x <= mx; x++)
				max_x = max(min(prefix[x][l - 1], prefix[x][n] - prefix[x][r]), max_x);
			max_l = max(2 * max_x + max_y, max_l);
		}
	
	return max_l;
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
		cout << three_blocks(n, a) << endl;
	}
	return 0;
}