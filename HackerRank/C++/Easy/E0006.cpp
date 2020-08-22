/*
Problem Statement: https://www.hackerrank.com/challenges/c-tutorial-functions/problem
*/

#include <iostream>
#include <cmath>

using namespace std;

int max_of_four(int a, int b, int c, int d) {
	return max(a, max(b, max(c, d)));
}

int main() {
	int a, b, c, d;
	cin >> a >> b >> c >> d;
	cout << max_of_four(a, b, c, d);
	return 0;
}