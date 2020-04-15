/*
Problem Statement: https://leetcode.com/problems/happy-number/
*/

class Solution {
public:
	int f(int x) {
		int sum = 0;
		while (x) {
			sum += (x % 10) * (x % 10);
			x /= 10;
		}
		return sum;
	}

    bool isHappy(int n) {
		int a, b;
		a = b = n;
		
		// Floyd's algorithm
		do {
			a = f(a);
			b = f(f(b));
		} while (a != b);
		
		return a == 1;
    }
};