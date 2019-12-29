/*
Problem Statement: https://www.hackerrank.com/challenges/30-more-exceptions/problem
*/

#include <iostream>
#include <cmath>
#include <stdexcept>

using namespace std;

class Calculator {
public:
	static int power(int n, int p) {
		if (n < 0 || p < 0)
			throw invalid_argument("n and p should be non-negative");
		else
			return pow(n, p);
	}
};