// Problem Code: abc172_b

#include <iostream>
#include <string>

using namespace std;

int minor_change(string& S, string& T) {
	int cnt = 0;
	for (int i = 0; i < S.length(); i++)
		cnt += S[i] != T[i];
	return cnt;
}

int main() {
	string S, T;
	cin >> S >> T;
	cout << minor_change(S, T);
	return 0;
}