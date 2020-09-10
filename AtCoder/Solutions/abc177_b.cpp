// Problem Code: abc177_b

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int substring(string& S, string& T) {
	int m, n, min_cnt;
	m = S.length();
	n = min_cnt = T.length();
	
	for (int i = 0; i + n <= m; i++) {
		int cnt = 0;
		for (int j = 0; j < n; j++)
			cnt += (S[i + j] != T[j]);
		min_cnt = min(cnt, min_cnt);
	}
	
	return min_cnt;
}

int main() {
	string S, T;
	cin >> S >> T;
	cout << substring(S, T);
	return 0;
}