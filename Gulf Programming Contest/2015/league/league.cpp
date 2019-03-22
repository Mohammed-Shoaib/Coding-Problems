#include <iostream>
#include <cstdio>

using namespace std;

int league(int T) {
	return T - 1;
}

int main() {
	freopen("league.in", "r", stdin);
	freopen("output.out", "w", stdout);
	
	int N, k = 1;
	cin >> N;
	while (N--) {
		int T;
		cin >> T;
		cout << k << ". " << league(T) << endl;
		k++;
	}

	return 0;
}