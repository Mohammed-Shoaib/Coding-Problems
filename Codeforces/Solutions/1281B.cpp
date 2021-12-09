// Problem Code: 1281B

#include <iostream>
#include <string>
#include <vector>

using namespace std;

string azamon(string& s, string& c) {
	int n = s.length();
	vector<int> pos(n);
	pos[n - 1] = n - 1;
	
	for (int i = n - 2; i >= 0; i--) {
		if (s[i] < s[pos[i + 1]])
			pos[i] = i;
		else
			pos[i] = pos[i + 1];
	}
	
	for (int i = 0; i < min(s.length(), c.length()); i++) {
		swap(s[i], s[pos[i]]);
		if (s < c)
			return s;
		swap(s[i], s[pos[i]]);
	}
	
	return "---";
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		string s, c;
		cin >> s >> c;
		cout << azamon(s, c) << endl;
	}
	return 0;
}