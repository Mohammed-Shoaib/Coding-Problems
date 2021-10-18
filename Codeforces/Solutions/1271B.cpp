// Problem Code: 1271B

#include <iostream>
#include <string>
#include <vector>

using namespace std;

char flip(char c) {
	return (c == 'W') ? 'B' : 'W';
}

void blocks(int n, string& s) {
	char c = 'B';
	vector<int> moves;

	for (int k = 1; k <= 2; k++) {
		c = flip(c);
		for (int i = 0; i < n - 1; i++)
			if (s[i] != c) {
				s[i] = flip(s[i]);
				s[i + 1] = flip(s[i + 1]);
				moves.push_back(i + 1);
			}
		if (s[n - 1] == c)
			break;
	}

	if (s[n - 1] != c) {
		cout << -1;
		return;
	}

	cout << moves.size() << endl;
	for (int i = 0; i < moves.size(); i++)
		cout << moves[i] << " ";
}

int main() {
	int n;
	string s;
	cin >> n >> s;
	blocks(n, s);
	return 0;
}