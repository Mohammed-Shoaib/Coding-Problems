/*
Problem Statement: https://leetcode.com/problems/four-divisors/
*/

class Solution {
public:
	int sumFourDivisors(vector<int>& nums) {
		int div_cnt, div_sum, sum = 0;
		for (int num: nums) {
			div_cnt = div_sum = 0;
			for (int i = 1; i * i <= num; i++)
				if (num % i == 0) {		// Add the divisor
					div_cnt++;
					div_sum += i;
					if (num > i * i) {	// Not a square, add the other divisor
						div_cnt++;
						div_sum += num / i;
					}
				}
			if (div_cnt == 4)
				sum += div_sum;
		}
		return sum;
	}
};