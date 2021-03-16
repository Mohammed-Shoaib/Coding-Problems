/*
Problem Statement: https://leetcode.com/problems/count-the-number-of-consistent-strings/
Time: O(n • len)
Space: O(1)
Author: Mohammed Shoaib, github.com/Mohammed-Shoaib
*/

class Solution {
public:
	int countConsistentStrings(string allowed, vector<string>& words) {
		int consistent = 0;
		unordered_set<char> seen(allowed.begin(), allowed.end());
		
		for (string& word: words)
			consistent += all_of(word.begin(), word.end(), [&seen](char& c) { 
				return seen.count(c);
			});
		
		return consistent;
	}
};