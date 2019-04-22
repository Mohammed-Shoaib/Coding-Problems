#include <iostream>
#include <cstdio>
#include <string>
#include <deque>

using namespace std;

string secret(string S) {
	int prev = 0;
	string s, M;
	deque<string> d;
	for (int i = 1; i < S.length(); i++)
		if (isdigit(S[i])) {
			s = S.substr(prev, i - prev);
			if ((S[i] - '0') & 1)
				d.push_back(s);
			else
				d.push_front(s);
			prev = i + 1;
		}
	for (string s: d)
		M += s;
	return M;
}

int main() {
	freopen("secret.in", "r", stdin);
	freopen("output.out", "w", stdout);
	
	int T, k = 1;
	cin >> T;
	while (T--) {
		string S;
		cin >> S;
		cout << k << ". " << secret(S) << endl;
		k++;
	}

	return 0;
}