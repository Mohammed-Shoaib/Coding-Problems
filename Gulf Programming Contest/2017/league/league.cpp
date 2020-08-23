#include <iostream>
#include <cstdio>

using namespace std;

int league(int N) {
	return (N - 1) * 6;
}

int main() {
	freopen("league.in", "r", stdin);
	freopen("output.out", "w", stdout);
	int T, k = 1;
	cin >> T;
	while (T--) {
		int N;
		cin >> N;
		cout << k << ". " << league(N) << endl;
		k++;
	}
	return 0;
}