// Problem Code: abc176_a

#include <iostream>

using namespace std;

int takoyaki(int N, int X, int T) {
	return (N + X - 1) / X * T;
}

int main() {
	int N, X, T;
	cin >> N >> X >> T;
	cout << takoyaki(N, X, T);
	return 0;
}