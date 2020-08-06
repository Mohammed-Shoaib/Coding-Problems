// Problem Code: 1399C

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int boats_competition(int n, vector<int>& w) {
	int max_cnt = 0;
	vector<int> freq(n + 1);

	for (int& x: w)
		freq[x]++;
	
	for (int s = 2; s <= 2 * n; s++) {
		int cnt = 0;
		for (int x = max(1, s - n); x <= s / 2; x++) {
			if (2 * x == s)
				cnt += freq[x] / 2;
			else
				cnt += min(freq[x], freq[s - x]);
		}
		max_cnt = max(cnt, max_cnt);
	}

	return max_cnt;
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		vector<int> w(n);
		for (int i = 0; i < n; i++)
			cin >> w[i];
		cout << boats_competition(n, w) << endl;
	}
	return 0;
}