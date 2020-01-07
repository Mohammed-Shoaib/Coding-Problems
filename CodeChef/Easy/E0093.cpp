// Problem Code: EVIPRO

#include <iostream>
#include <string>

using namespace std;

long long evil_professor(string& S) {
	int cnt, n = S.length();
	long long total = 0;
	
	// Initialize
	for (int i = 1; i < n; i++)
		if (S[i - 1] == S[i])
			total++;
	total *= 1LL * n * (n + 1) / 2;
	
	// Go through possible substrings
	for (int i = 1; i < n; i++) {
		cnt = (S[i - 1] == S[i]) ? -1 : 1;
		total += cnt * (n - i);
	}
	for (int i = 0; i < n - 1; i++) {
		cnt = (S[i] == S[i + 1]) ? -1 : 1;
		total += cnt * (i + 1);
	}

	return total;
}

int main() {
	int T;
	cin >> T;
	while (T--) {
		string S;
		cin >> S;
		cout << evil_professor(S) << endl;
	}	
	return 0;
}