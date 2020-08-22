/*
Problem Statement: https://leetcode.com/problems/print-words-vertically/
Time: O(words • len)
Space: O(words • len)
Author: Mohammed Shoaib, github.com/Mohammed-Shoaib
*/

class Solution {
public:
	vector<string> printVertically(string& s) {
		int row = 0, col = 0;
		vector<string> words;
		for (char c: s) {
			if (c == ' ') {
				row = 0;
				col++;
				continue;
			}
			if (words.size() == row)
				words.push_back(string());
			if (words[row].length() < col)
				words[row] += string(col - words[row].length(), ' ');
			words[row++] += c;
		}
		return words;
	}
};