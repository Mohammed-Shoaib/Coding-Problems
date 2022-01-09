// Problem Code: 1373B

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string game(string& s) {
	int zeros, ones, turn;
	zeros = count(s.begin(), s.end(), '0');
	ones  = count(s.begin(), s.end(), '1');
	turn  = min(zeros, ones) & 1;
	return turn ? "DA" : "NET";
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		string s;
		cin >> s;
		cout << game(s) << endl;
	}
	return 0;
}