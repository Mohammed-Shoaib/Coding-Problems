/*
Problem Statement: https://leetcode.com/problems/count-primes/
Time: O(n + sqrt(n) • log n)
Space: O(n)
Author: Mohammed Shoaib, github.com/Mohammed-Shoaib
*/

class Solution {
public:
	int countPrimes(int n) {
		// base case
		if (n <= 2)
			return 0;
		
		vector<bool> primes(n, true);
		
		// special case for 2
		int cnt = 1;
		for (int j = 4; j < n; j += 2)
			primes[j] = false;
		
		// sieve of eratosthenes
		for (int i = 3; i * i < n; i += 2) {
			if (!primes[i])
				continue;
			for (int j = i * i; j < n; j += i)
				primes[j] = false;
		}
		
		// count primes
		for (int i = 3; i < n; i += 2)
			cnt += primes[i];
		
		return cnt;
	}
};