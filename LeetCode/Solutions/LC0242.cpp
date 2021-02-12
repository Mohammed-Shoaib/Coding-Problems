/*
Problem Statement: https://leetcode.com/problems/valid-anagram/
Time: O(s + t)
Space: O(1)
Author: Mohammed Shoaib, github.com/Mohammed-Shoaib
*/

class Solution {
public:
	bool isAnagram(string s, string t) {
		unordered_map<char, int> freq;
		
		if (s.length() != t.length())
			return false;
		
		for (char& c: s)
			freq[c]++;
		
		for (char& c: t)
			if (freq[c]-- == 0)
				return false;
		
		return true;
	}
};