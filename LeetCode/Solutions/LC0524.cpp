/*
Problem Statement: https://leetcode.com/problems/longest-word-in-dictionary-through-deleting/
Time: O(n • max_len)
Space: O(max_len)
Author: Mohammed Shoaib, github.com/Mohammed-Shoaib
*/

class Solution {
public:
	string findLongestWord(string s, vector<string>& d) {
		string longest;
		for (string& w: d)
			if ((longest.length() < w.length() ||
				longest.length() == w.length() && longest > w)
				&& is_subsequence(w, s))
					longest = w;
		return longest;
	}
	
	bool is_subsequence(string& w, string& s) {
		int i = 0;
		for (char& c: s) {
			if (i == w.length())
				break;
			else if (c == w[i])
				i++;
		}
		return i == w.length();
	}
};