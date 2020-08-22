/*
Problem Statement: https://leetcode.com/problems/valid-anagram/
Time: O(s + t)
Space: O(s + t)
Author: Mohammed Shoaib, github.com/Mohammed-Shoaib
*/

class Solution {
public:
	bool isAnagram(string s, string t) {
		unordered_map<char, int> freq;
		for (char c: s)
			freq[c]++;
		for (char c: t)
			freq[c]--;
		for (auto it: freq)
			if (it.second)
				return false;
		return true;
	}
};