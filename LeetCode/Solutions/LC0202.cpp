/*
Problem Statement: https://leetcode.com/problems/happy-number/
Time: O(1)
Space: O(1)
Author: Mohammed Shoaib, github.com/Mohammed-Shoaib
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
		
		// floyd's cycle-finding algorithm
		do {
			a = f(a);
			b = f(f(b));
		} while (a != b);
		
		return a == 1;
	}
};