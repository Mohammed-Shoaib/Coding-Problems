// Problem Code: 1265C

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> award(int n, vector<int>& p) {
	int pos = 0;
	vector<int> res(3);
	n /= 2;

	// Gold
	while (pos < n && p[0] == p[pos]) {
		res[0]++;
		pos++;
	}

	// Silver
	while (pos < n && (res[0] >= res[1] || p[pos - 1] == p[pos])) {
		res[1]++;
		pos++;
	}

	// Bronze
	while (p[pos] != p[n]) {
		res[2]++;
		pos++;
	}

	if (res[0] >= res[2])
		fill(res.begin(), res.end(), 0);
	
	return res;
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		vector<int> res, p(n);
		for (int i = 0; i < n; i++)
			cin >> p[i];
		res = award(n, p);
		for (int i = 0; i < res.size(); i++)
			cout << res[i] << " ";
		cout << endl;
	}
	return 0;
}