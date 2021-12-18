// Problem Code: 1335E2

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int three_blocks(int n, vector<int>& a) {
	int max_l, mn, mx;
	max_l = 0;
	mn = *min_element(a.begin(), a.end());
	mx = *max_element(a.begin(), a.end());
	vector<vector<int>> pos(mx + 1), prefix(mx + 1, vector<int>(n + 1));

	// compute prefix sum array
	for (int x = mn; x <= mx; x++)
		for (int i = 0, j = 0; i < n; i++) {
			prefix[x][i + 1] = prefix[x][i] + (a[i] == x);
			if (a[i] == x)
				pos[x].push_back(i);
		}
	
	// try all x in the range [mn, mx]
	for (int x = mn; x <= mx; x++) {
		int cnt_x, cnt_y, l, r;
		cnt_x = pos[x].size();
		max_l = max(cnt_x, max_l);		// we only use x

		// we can take letters in the range [1, cnt_x / 2] for left and right
		for (int i = 0; i < cnt_x / 2; i++) {
			l = pos[x][i] + 2;
			r = pos[x][cnt_x - i - 1];

			// find max possible y in the range [l, r]
			for (int y = mn; y <= mx; y++) {
				int cnt_y = prefix[y][r] - prefix[y][l - 1];
				max_l = max(2 * (i + 1) + cnt_y, max_l);
			}
		}
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