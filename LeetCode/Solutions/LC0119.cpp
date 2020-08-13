/*
Problem Statement: https://leetcode.com/problems/pascals-triangle-ii/
Time: O(n)
Space: O(n)
Author: Mohammed Shoaib, github.com/Mohammed-Shoaib
*/

class Solution {
public:
	vector<int> getRow(int rowIndex) {
		vector<int> row(rowIndex + 1, 1);
		for (int i = 1; i <= rowIndex / 2; ++i) {
			int nCr = (long long) row[i - 1] * (rowIndex - i + 1) / i;
			row[i] = row[rowIndex - i] = nCr;
		}
		return row;
	}
};