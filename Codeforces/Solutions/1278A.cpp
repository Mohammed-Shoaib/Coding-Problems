// Problem Code: 1278A

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string shuffle_hashing(string& p, string& h) {
	int cnt, n, prev, curr, l;
	cnt = 0;
	l = 26;
	n = p.length();
	vector<bool> eq(l);
	vector<int> freq_p(l), freq_h(l);

	// Lambda function
	auto chg = [&](int pos, int val) {
		freq_h[pos] += val;
		cnt -= eq[pos];
		eq[pos] = (freq_p[pos] == freq_h[pos]);
		cnt += eq[pos];
	};

	// Initialize
	for (char c: p)
		freq_p[c - 'a']++;
	for (int i = 0; i < l; i++) {
		eq[i] = (freq_p[i] == freq_h[i]);
		cnt += eq[i];
	}

	// Find substring that can be reordered
	for (int i = 0; i < h.length(); i++) {
		if (i >= n)
			chg(h[i - n] - 'a', -1);
		chg(h[i] - 'a', 1);
		if (cnt == l)
			return "YES";
	}
	
	return "NO";
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		string p, h;
		cin >> p >> h;
		cout << shuffle_hashing(p, h) << endl;
	}
	return 0;
}