// Problem Code: 1527B1

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string palindrome_game(int n, string& s) {
	int zeros = count(s.begin(), s.end(), '0');
	if (zeros & 1)
		return --zeros ? "ALICE" : "BOB";
	return zeros ? "BOB" : "DRAW";
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