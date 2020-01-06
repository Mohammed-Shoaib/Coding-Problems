// Problem Code: STUPMACH

#include <iostream>
#include <vector>

using namespace std;

long long stupid_machine(int N, vector<int>& S) {
	int min_cap = S[0];
	long long cap = 0;
	for (int i = 0; i < N; i++) {
		min_cap = min(S[i], min_cap);
		cap += min_cap;
	}
	return cap;
}

int main() {
	int T;
	cin >> T;
	while (T--) {
		int N;
		cin >> N;
		vector<int> S(N);
		for (int i = 0; i < N; i++)
			cin >> S[i];
		cout << stupid_machine(N, S) << endl;
	}
	return 0;
}