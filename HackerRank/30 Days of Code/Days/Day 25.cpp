/*
Problem Statement: https://www.hackerrank.com/challenges/30-running-time-and-complexity/problem
*/

#include <iostream>
#include <string>
#include <cmath>

using namespace std;

string prime(int n) {
	if ((n == 1) || (n != 2 && n % 2 == 0))	// Number is 1 or divisible by 2
		return "Not prime";

	int root = sqrt(n);
	for (int x = 3; x <= root; x += 2)	// Go through odd numbers <= sqrt(n)
		if (n % x == 0)
			return "Not prime";
	
	return "Prime";
}

int main() {
	int T, n;
	cin >> T;
	while (T--) {
		cin >> n;
		cout << prime(n) << endl;
	}
}