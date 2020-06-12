// Problem Code: abc158_e

#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

long long divisible_substring(int N, int P, string& S) {
	int res, p;
	long long cnt;
	cnt = res = 0;
	unordered_map<int, long long> m;
	
	if (P == 2 || P == 5) {
		for (int i = 0; i < N; i++)
			if ((S[i] - '0') % P == 0)
				cnt += i + 1;
		return cnt;
	}
	
	m[0] = p = 1;
	for (int i = N - 1; i >= 0; i--) {
		res = (res + (S[i] - '0') * p) % P;
		m[res]++;
		p = (10 * p) % P;
	}
	for (auto it: m)
		cnt += it.second * (it.second - 1) / 2;
	
	return cnt;
}

int main() {
	int N, P;
	string S;
	cin >> N >> P >> S;
	cout << divisible_substring(N, P, S);
	return 0;
}
