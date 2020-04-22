/*
Problem Statement: https://leetcode.com/problems/valid-anagram/
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