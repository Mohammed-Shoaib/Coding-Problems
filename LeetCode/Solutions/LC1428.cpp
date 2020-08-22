/*
Problem Statement: https://leetcode.com/problems/leftmost-column-with-at-least-a-one/
Time: O(min(n, m))
Space: O(1)
Author: Mohammed Shoaib, github.com/Mohammed-Shoaib
*/

class Solution {
public:
	int leftMostColumnWithOne(BinaryMatrix &binaryMatrix) {
		int pos, n, m;
		pos = -1;
		n = binaryMatrix.dimensions()[0];
		m = binaryMatrix.dimensions()[1];
		
		int i = 0, j = m - 1;
		while (i < n && j >= 0) {
			if (binaryMatrix.get(i, j))
				pos = j--;
			else
				i++;
		}
		
		return pos;
	}
};