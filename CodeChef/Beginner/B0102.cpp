// Problem Code: CHEALG

#include <iostream>
#include <string>

using namespace std;

string check_algorithm(string& S) {
	int cnt, len = 0;
	for (int j, i = 0; i < S.length(); i++, len++) {
		j = i;
		while (i + 1 < S.length() && S[i + 1] == S[j])
			i++;
		cnt = i - j + 1;
		while (cnt) {
			len++;
			cnt /= 10;
		}
	}
	return (len < S.length()) ? "YES" : "NO";
}

int main() {
	int T;
	cin >> T;
	while (T--) {
		string S;
		cin >> S;
		cout << check_algorithm(S) << endl;
	}
	return 0;
}