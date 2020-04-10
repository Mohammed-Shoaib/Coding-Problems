#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string nesting_depth(string& S) {
	string s;
	int d, depth = 0;
	for (char c: S) {
		d = c - '0';
		s += string(max(0, d - depth), '(');
		s += string(max(0, depth - d), ')');
		s += c;
		depth = d;
	}
	s += string(depth, ')');
	return s;
}

int main() {
	int T;
	cin >> T;
	for (int x = 1; x <= T; x++) {
		string S;
		cin >> S;
		cout << "Case #" << x << ": " << nesting_depth(S) << endl;
	}
	return 0;
}