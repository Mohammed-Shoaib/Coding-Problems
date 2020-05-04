/*
Problem Statement: https://leetcode.com/problems/ransom-note/
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