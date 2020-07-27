/*
Problem Statement: https://leetcode.com/problems/add-digits/
Time: O(1)
Space: O(1)
Author: Mohammed Shoaib, github.com/Mohammed-Shoaib
*/

class Solution {
public:
	int addDigits(int num) {
		return (num - 1) % 9 + 1;
	}
};