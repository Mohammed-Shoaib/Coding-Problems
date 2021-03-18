/*
Problem Statement: https://leetcode.com/problems/count-of-matches-in-tournament/
Time: O(log n)
Space: O(1)
Author: Mohammed Shoaib, github.com/Mohammed-Shoaib
*/

class Solution {
public:
	int numberOfMatches(int n) {
		int matches = 0;
		while (n > 1) {
			matches += n / 2;
			n = (n + 1) / 2;
		}
		return matches;
	}
};