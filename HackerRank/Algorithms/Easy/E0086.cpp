/*
Problem Statement: https://www.hackerrank.com/challenges/flipping-bits/problem
*/

#include <iostream>
#include <bitset>

using namespace std;

long flippingBits(long n) {
	return bitset<32> (n).flip().to_ulong();
}

int main() {
	int q;
	cin >> q;
	while (q--) {
		long n;
		cin >> n;
		cout << flippingBits(n) << endl;
	}
}