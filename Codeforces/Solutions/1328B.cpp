// Problem Code: 1328B

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string beautiful(int n, int k) {
	int p = 1;
	string s(n, 'a');
	while (p < k) {
		k -= p;
		p++;
	}
	s[p] = s[--k] = 'b';
	reverse(s.begin(), s.end());
	return s;
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n, k;
		cin >> n >> k;
		cout << beautiful(n, k) << endl;
	}
	return 0;
}