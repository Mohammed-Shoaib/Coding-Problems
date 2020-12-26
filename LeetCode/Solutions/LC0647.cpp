/*
Problem Statement: https://leetcode.com/problems/palindromic-substrings/
Time: O(n²)
Space: O(1)
Author: Mohammed Shoaib, github.com/Mohammed-Shoaib
*/

class Solution {
public:
	int countSubstrings(string& s) {
		int cnt = 0, n = s.length();
		for (int i = 0; i < n; i++) {
			cnt += count_palindromes(i, i, s);		// odd palindromes
			cnt += count_palindromes(i, i + 1, s);	// even palindromes
		}
		return cnt;
	}
	
	int count_palindromes(int beg, int end, string& s) {
		int cnt = 0;
		while (beg >= 0 && end < s.length() && s[beg--] == s[end++])
			cnt++;
		return cnt;
	}
};