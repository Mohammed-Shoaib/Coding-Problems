#include <iostream>
#include <string>
#include <vector>

using namespace std;

void increasing_substring(int N, string& S) {
	vector<int> L(N, 1);
	
	for (int i = 1; i < N; i++)
		if (S[i - 1] < S[i])
			L[i] += L[i - 1];
	
	for (int& x: L)
		cout << x << " ";
	cout << endl;
}

int main() {
	int T;
	cin >> T;
	for (int x = 1; x <= T; x++) {
		int N;
		string S;
		cin >> N >> S;
		cout << "Case #" << x << ": ";
		increasing_substring(N, S);
	}
	return 0;
}