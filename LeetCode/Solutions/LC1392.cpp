/*
Problem Statement: https://leetcode.com/problems/longest-happy-prefix/
Time: O(n)
Space: O(n)
Author: Mohammed Shoaib, github.com/Mohammed-Shoaib
*/

class Solution {
public:
	string longestPrefix(string s) {
		int n = s.length();
		vector<int> pi(n);

		// prefix function
		for (int i = 1, j = 0; i < n; i++) {
			while (j > 0 && s[i] != s[j])
				j = pi[j - 1];
			if (s[i] == s[j])
				j++;
			pi[i] = j;
		}

		return s.substr(0, pi.back());
	}
};