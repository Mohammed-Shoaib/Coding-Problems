// Problem Code: 1296C

#include <iostream>
#include <string>
#include <map>
#include <utility>

using namespace std;

void optimize_robot(int n, string& s) {
	int l, r;
	pair<int, int> p = {0, 0};
	map<pair<int, int>, int> m;
	r = n;
	m[p] = l = -1;
	
	for (int i = 0; i < n; m[p] = i++) {
		// move robot to new position
		if (s[i] == 'L')
			p.first--;
		else if (s[i] == 'R')
			p.first++;
		else if (s[i] == 'D')
			p.second--;
		else
			p.second++;
		
		// if cycle found, update distance
		if (m.count(p) && i - m[p] < r - l + 1) {
			l = m[p] + 1;
			r = i;
		}
	}

	if (l == -1)
		cout << -1 << endl;
	else
		cout << l + 1 << " " << r + 1 << endl;
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n;
		string s;
		cin >> n >> s;
		optimize_robot(n, s);
	}
	return 0;
}