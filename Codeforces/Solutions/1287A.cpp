// Problem Code: 1287A

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int angry_students(int k, string& s) {
	int t, max_t = 0;
	for (size_t i = s.find('A'); i < k; i++) {
		if (s[i] == 'A')
			t = 0;
		max_t = max(t++, max_t);
	}
	return max_t;
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		int k;
		string s;
		cin >> k >> s;
		cout << angry_students(k, s) << endl;
	}
	return 0;
}