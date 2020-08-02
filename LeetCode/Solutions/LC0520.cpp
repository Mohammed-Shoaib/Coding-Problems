/*
Problem Statement: https://leetcode.com/problems/detect-capital/
Time: O(n)
Space: O(1)
Author: Mohammed Shoaib, github.com/Mohammed-Shoaib
*/

class Solution {
public:
	bool detectCapitalUse(string word) {
		bool is_lower = all_of(word.begin() + 1, word.end(), [](unsigned char c) { return islower(c); });
		bool is_upper = all_of(word.begin(), word.end(), [](unsigned char c) { return isupper(c); });
		return is_lower || is_upper;
	}
};