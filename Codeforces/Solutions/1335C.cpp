// Problem Code: 1335C

#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

int two_teams(int n, vector<int>& a) {
	int u, mx = 0;
	unordered_map<int, int> freq;

	for (int& x: a)
		freq[x]++;
	u = freq.size();
	
	for (auto& [k, v]: freq) {
		if (u == v)
			mx = max(u - 1, mx);
		else
			mx = max(min(u, v), mx);
	}
	
	return mx;
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
		cout << two_teams(n, a) << endl;
	}
	return 0;
}