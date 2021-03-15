/*
Problem Statement: https://leetcode.com/problems/check-if-two-string-arrays-are-equivalent/
Time: O(n)
Space: O(1)
Author: Mohammed Shoaib, github.com/Mohammed-Shoaib
*/

class Solution {
public:
	bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
		int i1, i2, p1, p2;
		i1 = i2 = p1 = p2 = 0;
		
		while (i1 < word1.size() && i2 < word2.size()) {
			string &w1 = word1[i1], &w2 = word2[i2];
			
			if (w1[p1] != w2[p2])
				return false;
			
			if (++p1 == w1.length()) {
				p1 = 0;
				++i1;
			}
			
			if (++p2 == w2.length()) {
				p2 = 0;
				++i2;
			}
		}
		
		return i1 == word1.size() && i2 == word2.size();
	}
};