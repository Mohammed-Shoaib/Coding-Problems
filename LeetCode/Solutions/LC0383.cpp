/*
Problem Statement: https://leetcode.com/problems/ransom-note/
Time: O(m + n)
Space: O(26)
Author: Mohammed Shoaib, github.com/Mohammed-Shoaib
*/

class Solution {
public:
	bool canConstruct(string ransomNote, string magazine) {
		vector<int> freq(26);
		for (char& c: magazine)
			freq[c - 'a']++;
		for (char& c: ransomNote)
			if (freq[c - 'a']-- == 0)
				return false;
		return true;
	}
};