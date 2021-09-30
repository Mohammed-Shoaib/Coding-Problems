// Problem Code: 1082B

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int vovaAndTrophies(int n, string S) {
	int len, maxLen, g;
	vector<int> L(n), R(n);

	len = maxLen = 0;
	g = count(S.begin(), S.end(), 'G');
	if (g == n)
		return g;
	if (S[0] == 'G')
		L[0] = 1;
	for (int i = 1 ; i < n ; i++) {
		if (S[i] == 'S')
			continue;
		L[i] = 1;
		L[i] += L[i - 1];
	}

	if (S[n - 1] == 'G')
		R[n - 1] = 1;
	for (int i = n - 2 ; i >= 0 ; i--) {
		if (S[i] == 'S')
			continue;
		R[i] = 1;
		R[i] += R[i + 1];
	}

	if (n == 1)
		maxLen = L[0];
	else {
		if (S[0] == 'S')
		maxLen = max(maxLen, R[1]);
		if (S[n - 1] == 'S') {
			maxLen = max(maxLen, L[n - 2]);
		}
	}

	for (int i = 1 ; i < n - 1 ; i++) {
		if (S[i] == 'G') 
			continue;
		len = L[i - 1] + R[i + 1];
		if (len < g) 
			len++;
		if (len > maxLen) 
			maxLen = len;
	}
	return maxLen;
}

int main() {
	int n;
	string S;
	cin >> n >> S;
	cout << vovaAndTrophies(n, S);
	return 0;
}