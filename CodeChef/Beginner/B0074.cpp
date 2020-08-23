// Problem Code: TALAZY

#include <iostream>
#include <cmath>

using namespace std;

long lazyJem(int N, int B, long M) {
	int P;
	long min = 0;
	while(N != 1) {
		P = ceil(N/2.0);
		min += P*M + B;
		N -= P;
		M *= 2;
	}
	min += N*M;
	return min;
}

int main() {
	int T, N, B, M;
	cin >> T;
	while(T--) {
		cin >> N >> B >> M;
		cout << lazyJem(N, B, M) << endl;
	}
	return 0;
}