/*
Problem Statement: https://leetcode.com/problems/ugly-number-iii/
Time: O(log (2 • 10⁹))
Space: O(1)
Author: Mohammed Shoaib, github.com/Mohammed-Shoaib
*/

class Solution {
public:
	long long lcm_ab, lcm_bc, lcm_ac, lcm_abc;
	
	int nthUglyNumber(int n, int a, int b, int c) {
		int mid, low = 1, high = 2e9;
		cout << high << endl;
		lcm_ab = lcm(a, b);
		lcm_bc = lcm(b, c);
		lcm_ac = lcm(a, c);
		lcm_abc = lcm(a, lcm_bc);
		
		// binary search
		while (low < high) {
			mid = low + (high - low) / 2;
			if (count(mid, a, b, c) < n)
				low = mid + 1;
			else
				high = mid;
		}
		
		return low;
	}
	
	long long lcm(long long a, long long b) {
		return (a * b) / gcd(a, b);
	}
	
	int count(int n, int a, int b, int c) {
		return n/a + n/b + n/c - n/lcm_ab - n/lcm_bc - n/lcm_ac + n/lcm_abc;
	}
};