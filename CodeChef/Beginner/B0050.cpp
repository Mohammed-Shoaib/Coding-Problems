// Problem Code: RECTSQ

#include <iostream>
#include <algorithm>

using namespace std;

int farmerAndHisPlot(int N, int M) {
	int gcd = __gcd(N, M);
	return (N*M)/(gcd*gcd);
}

int main() {
	int T, M, N;
	cin >> T;
	while(T--) {
		cin >> M >> N;
		cout << farmerAndHisPlot(N, M) << endl;
	}
	return 0;
}