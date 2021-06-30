/*
Problem Statement: https://leetcode.com/problems/sum-of-digits-in-base-k/
Time: O(n)
Space: O(1)
Author: Mohammed Shoaib, github.com/Mohammed-Shoaib
*/

class Solution {
public:
	int sumBase(int n, int k) {
		int sum = 0;
		while (n) {
			sum += n % k;
			n /= k;
		}
		return sum;
	}
};