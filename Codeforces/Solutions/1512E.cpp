/*
Problem Code: 1512E
Time: O(n²)
Space: O(n)
Author: Mohammed Shoaib, github.com/Mohammed-Shoaib
*/

#include <iostream>
#include <vector>
#include <set>
#include <utility>

using namespace std;

void permutation_by_sum(int n, int l, int r, int s) {
	int len, mn, mx;
	len = r - l + 1;
	mn = len * (len + 1) / 2;
	mx = len * (2 * n - len + 1) / 2;
	
	if (s < mn || s > mx) {
		cout << -1 << endl;
		return;
	}
	
	set<int> used;
	vector<int> perm(n + 1);
	
	for (int i = 1; i <= n; i++)
		used.insert(i);
	
	for (int i = l; i <= r; i++) {
		int next_s = (r - i) * (r - i + 1) / 2;
		for (auto it = used.rbegin(); it != used.rend(); it++) {
			int val = *it;
			if (s >= next_s + val) {
				perm[i] = val;
				s -= val;
				used.erase(next(it).base());
				break;
			}
		}
	}
	
	for (int i = 1; i < l; i++) {
		perm[i] = *used.begin();
		used.erase(used.begin());
	}
	
	for (int i = r + 1; i <= n; i++) {
		perm[i] = *used.begin();
		used.erase(used.begin());
	}
	
	for (int i = 1; i <= n; i++)
		cout << perm[i] << " ";
	cout << endl;
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n, l, r, s;
		cin >> n >> l >> r >> s;
		permutation_by_sum(n, l, r, s);
	}
	return 0;
}