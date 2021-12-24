// Problem Code: 1527B2

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

bool is_palindrome(int n, string& s) {
	return equal(s.begin(), s.begin() + n / 2, s.rbegin());
}

string easy_game(int n, string& s) {
	int zeros = count(s.begin(), s.end(), '0');
	if (zeros & 1)
		return --zeros ? "ALICE" : "BOB";
	return zeros ? "BOB" : "DRAW";
}

string hard_game(int n, string& s) {
	int zeros = count(s.begin(), s.end(), '0');
	return ((n & 1) && s[n / 2] == '0' && zeros == 2) ? "DRAW" : "ALICE";
}

string palindrome_game(int n, string& s) {
	if (is_palindrome(n, s))
		return easy_game(n, s);
	else
		return hard_game(n, s);
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n;
		string s;
		cin >> n >> s;
		cout << palindrome_game(n, s) << endl;
	}
	return 0;
}