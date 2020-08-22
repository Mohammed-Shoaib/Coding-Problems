/*
Problem Statement: https://www.hackerrank.com/challenges/sum-vs-xor/problem
*/

#include <iostream>

using namespace std;

long long sumXor(long long n) {
	int zeros = 0;
	while (n != 0) {
		if (n % 2 == 0)
			zeros++;
		n >>= 1;
	}
	return 1LL << zeros;
}

int main() {
	long long n;
	cin >> n;
	cout << sumXor(n) << endl;
	return 0;
}