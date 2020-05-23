/*
Problem Statement: https://leetcode.com/problems/leftmost-column-with-at-least-a-one/
*/

class Solution {
public:
	int leftMostColumnWithOne(BinaryMatrix &binaryMatrix) {
		int pos, n, i, j;
		pos = -1;
		n = binaryMatrix.dimensions()[0];
		i = 0;
		j = binaryMatrix.dimensions()[1] - 1;
		
		while (i < n && j >= 0) {
			if (binaryMatrix.get(i, j))
				pos = j--;
			else
				i++;
		}

		return pos;
	}
};