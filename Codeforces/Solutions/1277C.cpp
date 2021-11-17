// Problem Code: 1277C

#include <iostream>
#include <string>
#include <vector>

using namespace std;

void simple(string& s) {
	int n = s.length();
	string sub;
	vector<int> r;

	for (int i = 0; i < n; i++) {
		sub = s.substr(i, 3);
		if (sub == "one" || sub == "two") {
			if (i + 3 < n && s[i + 3] == 'n')
				i++;
			r.push_back(++i);
		}
	}

	cout << r.size() << endl;
	for (int pos: r)
		cout << pos + 1 << " ";
	cout << endl;
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		string s;
		cin >> s;
		simple(s);
	}
	return 0;
}