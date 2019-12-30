/*
Problem Statement: https://www.hackerrank.com/challenges/30-interfaces/problem
*/

#include <iostream>
#include <cmath>
#include <unordered_map>

using namespace std;

class Calculator : public AdvancedArithmetic {
public:
    int divisorSum(int n) {
		int num, den, sum = 1;
        unordered_map<int, int> factors;

		// Get the prime factorization of n
		for (int x = 2; x * x <= n; x++)
			while (n % x == 0) {
				factors[x]++;
				n /= x;
			}
		if (n > 1)
			factors[n]++;

		// Compute sum of factors
		for (auto& it: factors) {
			num = pow(it.first, it.second + 1) - 1;
			den = it.first - 1;
			sum *= num / den;
		}

		return sum;
    }
};