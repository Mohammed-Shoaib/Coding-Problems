// Problem Code: OMWG

#include <iostream>

using namespace std;

int oneMoreWeirdGame(int N, int M) {
	return N * (M - 1) + M * (N - 1);
}

int main() {
	int T;
	cin >> T;
	while (T--) {
		int N, M;
		cin >> N >> M;
		cout << oneMoreWeirdGame(N, M) << endl;
	}
    return 0;
}