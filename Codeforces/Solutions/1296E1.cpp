// Problem Code: 1296E1

#include <iostream>
#include <string>
#include <vector>

using namespace std;

void string_coloring(int n, string& s) {
	char s1, s2;
	vector<int> col(n);
	
	s1 = s2 = 'a';
	for (int i = 0; i < n; i++) {
		if (s1 <= s[i]) {
			s1 = s[i];
			col[i] = 0;
		} else if (s2 <= s[i]) {
			s2 = s[i];
			col[i] = 1;
		} else {
			cout << "NO" << endl;
			return;
		}
	}

	cout << "YES" << endl;
	for (int i = 0; i < n; i++)
		cout << col[i];
	cout << endl;
}

int main() {
	int n;
	string s;
	cin >> n >> s;
	string_coloring(n, s);
	return 0;
}