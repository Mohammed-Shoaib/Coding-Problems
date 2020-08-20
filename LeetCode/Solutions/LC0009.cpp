/*
Problem Statement: https://leetcode.com/problems/palindrome-number/
Time: O(n)
Space: O(1)
Author: Mohammed Shoaib, github.com/Mohammed-Shoaib
*/

class Solution {
public:
	bool isPalindrome(int x) {
		if (x && x % 10 == 0)
			return false;
		int rev = 0;
		while (x > rev) {
			rev = 10 * rev + x % 10;
			x /= 10;
		}
		return (rev == x) || (rev / 10 == x);
	}
};