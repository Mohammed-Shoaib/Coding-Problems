// Problem Code: FRUITS

#include <iostream>
#include <cmath>

using namespace std;

int chefAndFruits(int N, int M, int K) {
	int diff = abs(N - M);
	if(diff <= K)
		return 0;
	return abs(diff - K);
}

int main() {
	int T, N, M, K;
	cin >> T;
	while(T--) {
		cin >> N >> M >> K;
		cout << chefAndFruits(N, M, K) << endl;
	}
	return 0;
}