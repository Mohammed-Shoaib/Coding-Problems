/*
Problem Statement: https://www.hackerrank.com/challenges/maximizing-xor/problem
*/

#include <iostream>
#include <bitset>
#define M 32

using namespace std;

int maximizingXor(int l, int r) {
	int max, pos;
	bitset<M> L(l), R(r);
	max = 0;
	pos = M - 1;
	while (pos >= 0 && L[pos] == R[pos])
		pos--;
	while (pos >= 0) {
		max <<= 1;
		max ^= 1;
		pos--;
	}
	return max;
}

int main() {
	int l, r;
	cin >> l >> r;
	cout << maximizingXor(l, r);
	return 0;
}