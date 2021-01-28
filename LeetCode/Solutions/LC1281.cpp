/*
Problem Statement: https://leetcode.com/problems/subtract-the-product-and-sum-of-digits-of-an-integer/
*/

class Solution {
public:
	int subtractProductAndSum(int n) {
		int sum, prod, mod;
		sum = 0;
		prod = 1;
		mod = 10;
		while (n) {
			sum += n % mod;
			prod *= n % mod;
			n /= mod;
		}
		return prod - sum;
	}
};