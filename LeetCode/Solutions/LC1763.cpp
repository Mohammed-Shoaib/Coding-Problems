/*
Problem Statement: https://leetcode.com/problems/longest-nice-substring/
Time: O(n • log n)
Space: O(n • log n)
Author: Mohammed Shoaib, github.com/Mohammed-Shoaib
*/

class Solution {
public:
	string longestNiceSubstring(string s) {
		int n = s.length();
		vector<bool> freq(52);
		
		// preprocess
		for (char& c: s)
			freq[tolower(c) - 'a' + 26 * static_cast<bool>(isupper(c))] = true;
		
		// divide & conquer
		for (int i = 0; i < n; i++) {
			int j = tolower(s[i]) - 'a';
			if (freq[j] && freq[j + 26])
				continue;
			string s1, s2;
			s1 = longestNiceSubstring(s.substr(0, i));
			s2 = longestNiceSubstring(s.substr(i + 1));
			if (s1.length() >= s2.length())
				return s1;
			else
				return s2;
		}
		
		return s;
	}
};