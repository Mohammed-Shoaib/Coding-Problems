/*
Problem Statement: https://leetcode.com/problems/get-equal-substrings-within-budget/
Time: O(n)
Space: O(1)
Author: Mohammed Shoaib, github.com/Mohammed-Shoaib
*/

class Solution {
public:
	int equalSubstring(string& s, string& t, int maxCost) {
		int length, cost, n;
		length = cost = 0;
		n = s.length();
		
		for (int i = 0, j = 0; i < n; i++) {
			cost += abs(s[i] - t[i]);
			while (cost > maxCost) {
				cost -= abs(s[j] - t[j]);
				j++;
			}
			length = max(i - j + 1, length);
		}
		
		return length;
	}
};