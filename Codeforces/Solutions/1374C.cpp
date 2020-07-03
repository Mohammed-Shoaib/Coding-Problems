// Problem Code: 1374C

#include <iostream>
#include <string>

using namespace std;

int move_brackets(int n, string& s) {
	int moves, bal;
	moves = bal = 0;
	for (char& c: s) {
		if (c == '(')
			bal++;
		else if (bal > 0)
			bal--;
		else
			moves++;
	}
	return moves;
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n;
		string s;
		cin >> n >> s;
		cout << move_brackets(n, s) << endl;
	}
	return 0;
}