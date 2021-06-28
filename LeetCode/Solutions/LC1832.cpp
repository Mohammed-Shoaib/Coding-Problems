/*
Problem Statement: https://leetcode.com/problems/check-if-the-sentence-is-pangram/
Time: O(n)
Space: O(1)
Author: Mohammed Shoaib, github.com/Mohammed-Shoaib
*/

class Solution {
public:
	bool checkIfPangram(string sentence) {
		int mask = 0;
		for (char& c: sentence)
			mask |= 1 << (c - 'a');
		return mask == (1 << 26) - 1;
	}
};