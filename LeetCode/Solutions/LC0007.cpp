/*
Problem Statement: https://leetcode.com/problems/reverse-integer/
Time: O(n)
Space: O(1)
Author: Mohammed Shoaib, github.com/Mohammed-Shoaib
*/

class Solution {
private:
	const int pos_inf = numeric_limits<int>::max();
	const int neg_inf = numeric_limits<int>::min();
public:
	int reverse(int x) {
		int rev = 0;
		while (x) {
			// check overflow
			if (rev > pos_inf / 10 || rev < neg_inf / 10)
				return 0;
			rev = 10 * rev + x % 10;
			x /= 10;
		}
		return rev;
	}
};