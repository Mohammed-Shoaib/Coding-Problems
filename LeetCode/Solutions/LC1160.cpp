/*
Problem Statement: https://leetcode.com/problems/find-words-that-can-be-formed-by-characters/
Time: O(n • len)
Space: O(1)
Author: Mohammed Shoaib, github.com/Mohammed-Shoaib
*/

class Solution {
public:
	int countCharacters(vector<string>& words, string chars) {
		int sum = 0;
		vector<int> freq(26);
		
		for (char& c: chars)
			freq[c - 'a']++;
		
		for (string& word: words) {
			bool anagram = true;
			vector<int> copy(freq);
			for (char& c: word)
				anagram &= (copy[c - 'a']-- > 0);
			if (anagram)
				sum += word.length();
		}
		
		return sum;
	}
};