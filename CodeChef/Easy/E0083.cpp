// Problem Code: THREEDIF

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int threeDifferentNumbers(vector<long long> &N) {
	long long res = 1;
	int mod = 1e9 + 7;
	sort(N.begin(), N.end());
	for (int i = 0; i < N.size(); i++) {
		res *= (N[i] - i) % mod;
		res %= mod;
	}
	return res;
}

int main() {
	int T;
	cin >> T;
	while (T--) {
		vector<long long> N(3);
		for (int i = 0; i < N.size(); i++)
			cin >> N[i];
		cout << threeDifferentNumbers(N) << endl;
	}
	return 0;
}