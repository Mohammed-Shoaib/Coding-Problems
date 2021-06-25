/*
Problem Statement: https://leetcode.com/problems/determine-color-of-a-chessboard-square/
Time: O(1)
Space: O(1)
Author: Mohammed Shoaib, github.com/Mohammed-Shoaib
*/

class Solution {
public:
	bool squareIsWhite(string coordinates) {
		return (coordinates[0] - 'a' + coordinates[1] - '1') & 1;
	}
};