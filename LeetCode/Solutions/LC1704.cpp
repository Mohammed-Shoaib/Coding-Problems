/*
Problem Statement: https://leetcode.com/problems/determine-if-string-halves-are-alike/
Time: O(n)
Space: O(1)
Author: Mohammed Shoaib, github.com/Mohammed-Shoaib
*/

class Solution {
public:
	bool halvesAreAlike(string s) {
		int bal = 0, n = s.length();
		unordered_set<char> vowels = {'a', 'e', 'i', 'o', 'u'};
		
		for (int i = 0; i < n / 2; i++) {
			bal += vowels.count(tolower(s[i]));
			bal -= vowels.count(tolower(s[n - i - 1]));
		}
		
		return bal == 0;
	}
};