/*
Problem Statement: https://leetcode.com/problems/excel-sheet-column-title/
Time: O(log n)
Space: O(log n)
Author: Mohammed Shoaib, github.com/Mohammed-Shoaib
*/

class Solution {
public:
	string convertToTitle(int n) {
		string title;
		while (n--) {
			title += (n % 26) + 'A';
			n /= 26;
		}
		reverse(title.begin(), title.end());
		return title;
	}
};