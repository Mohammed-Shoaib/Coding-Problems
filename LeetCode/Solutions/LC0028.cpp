/*
Problem Statement: https://leetcode.com/problems/implement-strstr/
Time: O(n + m)
Space: O(m)
Author: Mohammed Shoaib, github.com/Mohammed-Shoaib
*/

class Solution {
public:
	int strStr(string& haystack, string& needle) {
		int n = haystack.size(), m = needle.size();
		
		// base case
		if (needle.empty())
			return 0;
		vector<int> pi(m);
		
		// prefix function
		for (int i = 1, j = 0; i < m; i++) {
			while (j > 0 && needle[i] != needle[j])
				j = pi[j - 1];
			if (needle[i] == needle[j])
				j++;
			pi[i] = j;
		}
		
		// knuth-morris-pratt algorithm
		for (int i = 0, j = 0; i < n; i++) {
			while (j > 0 && haystack[i] != needle[j])
				j = pi[j - 1];
			if (haystack[i] == needle[j])
				j++;
			if (j == m)
				return i - m + 1;
		}
		
		return -1;
	}
};