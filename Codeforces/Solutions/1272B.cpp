// Problem Code: 1272B

#include <iostream>
#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;

string make_valid(string& s) {
	int l, u;
	unordered_map<char, int> cnt;
	
	for (char c: s)
		cnt[c]++;
	
	// optimal way to construct directions
	l = min(cnt['L'], cnt['R']);
	u = min(cnt['U'], cnt['D']);

	// edge case
	if (u == 0)
		l = min(1, l);`
	else if (l == 0)
		u = 1;
	
	return string(l, 'L') + string(u, 'U') + string(l, 'R') + string(u, 'D');
}

int main() {
	int q;
	cin >> q;
	while (q--) {
		string s;
		cin >> s;
		s = make_valid(s);
		cout << s.length() << endl;
		cout << s << endl;
	}
	return 0;
}