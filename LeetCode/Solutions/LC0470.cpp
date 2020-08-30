/*
Problem Statement: https://leetcode.com/problems/implement-rand10-using-rand7/
Time: O(1)
Space: O(1)
Author: Mohammed Shoaib, github.com/Mohammed-Shoaib
*/

class Solution {
public:
	int rand10() {
		int a = rand7(), b = 7;
		while (a > 5)
			b = exchange(a, rand7()) - 1;
		while (b == 7)
			b = rand7();
		return 2 * a - (b & 1);
	}
};