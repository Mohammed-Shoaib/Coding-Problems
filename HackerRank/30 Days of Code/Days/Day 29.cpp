/*
Problem Statement: https://www.hackerrank.com/challenges/30-bitwise-and/problem
*/

#include <iostream>

using namespace std;

int bitwise_and(int N, int K) {
	int k = K | (K - 1);
	if (k <= N)
		return K - 1;
	else
		return K - 2;
}

int main() {
	int T;
	cin >> T;
	while (T--) {
		int N, K;
		cin >> N >> K;
		cout << bitwise_and(N, K) << endl;
	}
	return 0;
}