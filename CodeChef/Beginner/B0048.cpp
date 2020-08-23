// Problem Code: TRICOIN

#include <iostream>
#include <cmath>

using namespace std;

int coinsAndTriangle(long N) {
	return (-1 + sqrt(1 + 8*N))/2;
}

int main() {
	int T, N;
	cin >> T;
	while(T--) {
		cin >> N;
		cout << coinsAndTriangle(N) << endl;
	}
	return 0;
}