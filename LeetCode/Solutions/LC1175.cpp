/*
Problem Statement: https://leetcode.com/problems/prime-arrangements/
Time: O(n • sqrt(n))
Space: O(n)
Author: Mohammed Shoaib, github.com/Mohammed-Shoaib
*/

class Solution {
private:
	int count_primes(int n) {
		vector<int> prime(n + 1, true);
		
		// sieve of eratosthenes
		prime[0] = prime[1] = false;
		for (int i = 2; i * i <= n; i++) {
			if (!prime[i])
				continue;
			for (int j = 2 * i; j <= n; j += i)
				prime[j] = false;
		}
		
		return count(prime.begin(), prime.end(), true);
	}
	
	int factorial(int64_t x, int mod) {
		if (x == 0)
			return 1;
		for (int y = x - 1; y > 1; y--)
			x = (x * y) % mod;
		return x;
	}
	
public:
	int numPrimeArrangements(int n) {
		int primes = count_primes(n), mod = 1e9 + 7;
		int64_t a = factorial(primes, mod), b = factorial(n - primes, mod);
		return (a * b) % mod;
	}
};