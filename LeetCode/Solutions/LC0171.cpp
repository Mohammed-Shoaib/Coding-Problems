/*
Problem Statement: https://leetcode.com/problems/excel-sheet-column-number/
Time: O(n)
Space: O(1)
Author: Mohammed Shoaib, github.com/Mohammed-Shoaib
*/

class Solution {
public:
	int titleToNumber(string s) {
		return accumulate(s.begin(), s.end(), 0, [](int& num, char& c) {
			return 26 * num + (c - 'A' + 1);
		});
	}
};